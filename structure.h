// #include<iostream>
#include<vector>
#include<map>


enum class genre {
  hip_hop,
  heavy_metal,
  reggae,
  disco,
  rock,
  classical,
  soul,
  pop,
  folk,
  country,
  punk_rock,
  electronic,
  jazz,
  blues,
  funk,
  instrumental,
  dubstep,
};

enum class parameter{
  popularity,
  tempo,
  energy,
  happiness,
  acousticness,
};

class track {
  public:
    std::string name;
    std::vector<genre> genres;
    std::map<parameter, int> params;
};


/* Given Vector of tracks */

std::vector<track> givenTracks = {
    {.name = "slave_to_perfection", .genres = {genre::electronic, genre::dubstep}, .params = {{parameter::popularity, 50}, {parameter::tempo, 100}, {parameter::energy, 49}, {parameter::happiness, 27}, {parameter::acousticness, 7},} },
    {.name = "dream_on", .genres = {genre::rock}, .params = {{parameter::popularity, 79}, {parameter::tempo, 161}, {parameter::energy, 43}, {parameter::happiness, 22}, {parameter::acousticness, 39},} },
    {.name = "back_in_black", .genres = {genre::rock, genre::heavy_metal}, .params = {{parameter::popularity, 84}, {parameter::tempo, 94}, {parameter::energy, 70}, {parameter::happiness, 76}, {parameter::acousticness, 1},} },
    {.name = "wish_you_were_here", .genres = {genre::rock}, .params = {{parameter::popularity, 76}, {parameter::tempo, 123}, {parameter::energy, 26}, {parameter::happiness, 38}, {parameter::acousticness, 74},} },
    {.name = "44_More", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 69 }, {parameter::tempo, 140 }, {parameter::energy, 58 }, {parameter::happiness, 22 }, {parameter::acousticness, 7 },} },
    {.name = "Jump_Out_The_Window", .genres = { genre::hip_hop, genre::electronic }, .params = {{parameter::popularity, 65 }, {parameter::tempo, 137 }, {parameter::energy, 70 }, {parameter::happiness, 49 }, {parameter::acousticness, 14 },} },
    {.name = "MIDDLE_CHILD", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 82 }, {parameter::tempo, 124 }, {parameter::energy, 36 }, {parameter::happiness, 46 }, {parameter::acousticness, 15 },} },
    {.name = "DNA.", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 77 }, {parameter::tempo, 140 }, {parameter::energy, 52 }, {parameter::happiness, 42 }, {parameter::acousticness, 0 },} },
    {.name = "Stronger", .genres = { genre::hip_hop, genre::electronic }, .params = {{parameter::popularity, 80 }, {parameter::tempo, 104 }, {parameter::energy, 72 }, {parameter::happiness, 49 }, {parameter::acousticness, 1 },} },
    {.name = "Comfortably_Numb", .genres = { genre::rock, }, .params = {{parameter::popularity, 73 }, {parameter::tempo, 127 }, {parameter::energy, 37 }, {parameter::happiness, 17 }, {parameter::acousticness, 15 },} },
    {.name = "The_Day_That_Never_Comes", .genres = { genre::rock, genre::heavy_metal }, .params = {{parameter::popularity, 56 }, {parameter::tempo, 125 }, {parameter::energy, 99 }, {parameter::happiness, 48 }, {parameter::acousticness, 0 },} },
    {.name = "Ride", .genres = { genre::hip_hop, genre::rock }, .params = {{parameter::popularity, 81 }, {parameter::tempo, 75 }, {parameter::energy, 71 }, {parameter::happiness, 57 }, {parameter::acousticness, 1 },} },
    {.name = "Stressed_Out", .genres = { genre::hip_hop, genre::rock }, .params = {{parameter::popularity, 83 }, {parameter::tempo, 170 }, {parameter::energy, 64 }, {parameter::happiness, 65 }, {parameter::acousticness, 5 },} },
    {.name = "In_the_End", .genres = { genre::electronic, genre::rock }, .params = {{parameter::popularity, 84 }, {parameter::tempo, 105 }, {parameter::energy, 86 }, {parameter::happiness, 40 }, {parameter::acousticness, 1 },} },
    {.name = "Chop_Suey!", .genres = { genre::rock, genre::heavy_metal }, .params = {{parameter::popularity, 79 }, {parameter::tempo, 127 }, {parameter::energy, 93 }, {parameter::happiness, 29 }, {parameter::acousticness, 0 },} },
    {.name = "Sweet_Dreams_(Are_Made_Of_This)", .genres = { genre::rock, genre::punk_rock }, .params = {{parameter::popularity, 68 }, {parameter::tempo, 92 }, {parameter::energy, 64 }, {parameter::happiness, 13 }, {parameter::acousticness, 1 },} },
    {.name = "Never_Lie_(feat._Moneybagg_Yo)", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 61 }, {parameter::tempo, 140 }, {parameter::energy, 72 }, {parameter::happiness, 32 }, {parameter::acousticness, 3 },} },
    {.name = "Blinding_Lights", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 96 }, {parameter::tempo, 171 }, {parameter::energy, 73 }, {parameter::happiness, 33 }, {parameter::acousticness, 0 },} },
    {.name = "Heartless", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 80 }, {parameter::tempo, 170 }, {parameter::energy, 75 }, {parameter::happiness, 25 }, {parameter::acousticness, 2 },} },
    {.name = "Party_Monster", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 72 }, {parameter::tempo, 78 }, {parameter::energy, 63 }, {parameter::happiness, 22 }, {parameter::acousticness, 19 },} },
    {.name = "Controlla", .genres = { genre::hip_hop, genre::pop }, .params = {{parameter::popularity, 71 }, {parameter::tempo, 92 }, {parameter::energy, 47 }, {parameter::happiness, 35 }, {parameter::acousticness, 8 },} },
    {.name = "No_Role_Modelz", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 83 }, {parameter::tempo, 100 }, {parameter::energy, 52 }, {parameter::happiness, 46 }, {parameter::acousticness, 30 },} },
    {.name = "Nothing_Else_Matters", .genres = { genre::rock, genre::heavy_metal }, .params = {{parameter::popularity, 69 }, {parameter::tempo, 142 }, {parameter::energy, 36 }, {parameter::happiness, 17 }, {parameter::acousticness, 5 },} },
    {.name = "Come_As_You_Are", .genres = { genre::rock }, .params = {{parameter::popularity, 77 }, {parameter::tempo, 120 }, {parameter::energy, 82 }, {parameter::happiness, 54 }, {parameter::acousticness, 0 },} },
    {.name = "Hotel_California_-_2013_Remaster", .genres = { genre::rock }, .params = {{parameter::popularity, 83 }, {parameter::tempo, 147 }, {parameter::energy, 51 }, {parameter::happiness, 61 }, {parameter::acousticness, 1 },} },
    {.name = "Stairway_to_Heaven_-_Remaster", .genres = { genre::rock }, .params = {{parameter::popularity, 78 }, {parameter::tempo, 82 }, {parameter::energy, 34 }, {parameter::happiness, 20 }, {parameter::acousticness, 58 },} },
    {.name = "The_90s", .genres = { genre::electronic }, .params = {{parameter::popularity, 32 }, {parameter::tempo, 138 }, {parameter::energy, 94 }, {parameter::happiness, 77 }, {parameter::acousticness, 18 },} },
    {.name = "Wildfire", .genres = { genre::electronic }, .params = {{parameter::popularity, 35 }, {parameter::tempo, 80 }, {parameter::energy, 62 }, {parameter::happiness, 8 }, {parameter::acousticness, 3 },} },
    {.name = "Take_Five", .genres = { genre::jazz }, .params = {{parameter::popularity, 66 }, {parameter::tempo, 174 }, {parameter::energy, 26 }, {parameter::happiness, 60 }, {parameter::acousticness, 54 },} },
    {.name = "Georgia_on_My_Mind", .genres = { genre::jazz }, .params = {{parameter::popularity, 51 }, {parameter::tempo, 68 }, {parameter::energy, 23 }, {parameter::happiness, 18 }, {parameter::acousticness, 79 },} },
    {.name = "Tadow", .genres = { genre::electronic, genre::jazz }, .params = {{parameter::popularity, 77 }, {parameter::tempo, 122 }, {parameter::energy, 49 }, {parameter::happiness, 31 }, {parameter::acousticness, 67 },} },
    {.name = "It's_A_Man's,_Man's,_Man's_World", .genres = { genre::blues }, .params = {{parameter::popularity, 52 }, {parameter::tempo, 81 }, {parameter::energy, 35 }, {parameter::happiness, 55 }, {parameter::acousticness, 67 },} },
    {.name = "Uptown_Girl", .genres = { genre::blues }, .params = {{parameter::popularity, 77 }, {parameter::tempo, 129 }, {parameter::energy, 94 }, {parameter::happiness, 79 }, {parameter::acousticness, 7 },} },
    {.name = "The_A_Team", .genres = { genre::pop }, .params = {{parameter::popularity, 76 }, {parameter::tempo, 85 }, {parameter::energy, 29 }, {parameter::happiness, 41 }, {parameter::acousticness, 67 },} },
    {.name = "Everglow", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 68 }, {parameter::tempo, 146 }, {parameter::energy, 44 }, {parameter::happiness, 14 }, {parameter::acousticness, 46 },} },
    {.name = "Lean_On", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 72 }, {parameter::tempo, 98 }, {parameter::energy, 81 }, {parameter::happiness, 27 }, {parameter::acousticness, 0 },} },
    {.name = "Mind_(feat._Kai)", .genres = { genre::pop, genre::electronic }, .params = {{parameter::popularity, 65 }, {parameter::tempo, 174 }, {parameter::energy, 78 }, {parameter::happiness, 36 }, {parameter::acousticness, 12 },} },
    {.name = "Closer", .genres = { genre::electronic, genre::pop }, .params = {{parameter::popularity, 84 }, {parameter::tempo, 95 }, {parameter::energy, 52 }, {parameter::happiness, 66 }, {parameter::acousticness, 41 },} },
    {.name = "Isis_(feat._Logic)", .genres = { genre::hip_hop }, .params = {{parameter::popularity, 74 }, {parameter::tempo, 120 }, {parameter::energy, 94 }, {parameter::happiness, 76 }, {parameter::acousticness, 21 },} },
    {.name = "The_Box", .genres = { genre::hip_hop, genre::electronic, genre::pop }, .params = {{parameter::popularity, 89 }, {parameter::tempo, 117 }, {parameter::energy, 59 }, {parameter::happiness, 64 }, {parameter::acousticness, 10 },} },
};