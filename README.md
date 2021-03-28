# music_recommender
Music Recommender algorithm using knn trees and condensation for genre categorization
![image](https://user-images.githubusercontent.com/31028745/112745388-be5c9580-8fc5-11eb-908d-e5ee7db3dddf.png)

This is still quite a poor representation of the actual thing, but still it proves the\
point (This was a late night project and I was very sleepy, excuse my poor code 0w0 )\
The next step will be to rewrite the code properly and make a standard API for proper use.

## Further things to integrate
- [x] - euclidean distance
- [ ] - hamming distance
- [ ] - cosine distance
- [ ] - manhattan distance

Using aubio library for audio signal processing to extract the parameters from the tracks.

![image](https://user-images.githubusercontent.com/31028745/112745378-a258f400-8fc5-11eb-99a7-9bf638bad99f.png)\
The number of dimensions to our graph represents the multiple parameters that will be used to find the nearest neighbours

## Further Goals
More parameters (obviously*)\
Introducing multiple types of nodes in the graph (both users & tracks)
![image](https://user-images.githubusercontent.com/31028745/112745476-52c6f800-8fc6-11eb-9b61-2749e62ccc2a.png)
