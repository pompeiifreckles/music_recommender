from sys import argv
from selenium import webdriver
from bs4 import BeautifulSoup
import re

if len(argv) < 2:
    exit()
#  URL = 'https://tunebat.com/Info/44-More-Logic/3e7Y6sfFlIdBMJhX7wpqVO'
URL = argv[1]

driver = webdriver.Chrome('/snap/bin/chromium.chromedriver')
driver.get(URL)

content = driver.page_source
soup = BeautifulSoup(content, features='lxml')

#  for a in soup.findAll('a', href=True, attrs={'class':'attribute-table-element'}):
name = soup.find('h1', attrs={'class':'main-track-name'})
popularity = soup.find('div', attrs={'title':'Popularity'}).findAll('span')[1]
tempo = soup.findAll('div', attrs={'class':'main-attribute-value'})[-1]
energy = soup.find('td', attrs={'class':'attribute-table-element', 'title': '0 - 100 how intense and active the track is, based on general entropy, onset rate, timbre, perceived loudness, and dynamic range'})
happiness = soup.find('td', attrs={'class':'attribute-table-element', 'title': '0 - 100 how cheerful and positive the track is'})
acousticness = soup.find('td', attrs={'class':'attribute-table-element', 'title': '0 - 100 how likely the track is acoustic'})


#  print(happiness)
#  print(energy.text, happiness.text, acousticness.text)
print(name.text.strip())

name = re.sub(' ', '_', name.text.strip())

final_string = f'{{.name = "{name}", .genres = {{  }}, .params = {{{{parameter::popularity, {popularity.text} }}, {{parameter::tempo, {tempo.text} }}, {{parameter::energy, {energy.text} }}, {{parameter::happiness, {happiness.text} }}, {{parameter::acousticness, {acousticness.text} }},}} }},'
#  final_string = f'{name.text.strip()} {{}} {popularity.text} {tempo.text} {energy.text} {happiness.text} {acousticness.text}'

f = open('foo.txt', 'a+')
f.write(final_string)
f.write("\n")
f.close()
print(final_string)

