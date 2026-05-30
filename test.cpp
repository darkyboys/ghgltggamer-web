/*
MIT License

Copyright (c) 2026 darkyboys

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "utils.hh"
#include "widgets.hh"

int main(){
    
    std::vector<std::string> t = {
        "index.html"
    };

    file("proj.html", project_page(Project{
  "My Game",
  "Cool indie game about space",
  "/img/server-slot.webp",

  "https://github.com/me/game",
  "https://download-link.com",

  "MIT",        // license
  "1.0.0",      // version
  "main",       // branch

  {"game", "space", "indie", "2d"}, // tags

  {"/img/server-slot.webp",
   "/img/Tv-bg01.png",
   "/img/Rider.png"}
}));


    std::vector <Project> proj = {
        {
          "p1",
          "Cool indie game about space",
          "/img/server-slot.webp",

          "https://github.com/me/game",
          "https://download-link.com",

          "MIT",        // license
          "1.0.0",      // version
          "main",       // branch

          {"game", "space", "indie", "3d"}, // tags

          {"/img/server-slot.webp",
           "/img/Tv-bg01.png",
           "/img/Rider.png"}
        },



        {
          "p2",
          "Cool indie game about space",
          "/img/server-slot.webp",
                
          "https://github.com/me/game",
          "https://download-link.com",
                
          "MIT",        // license
          "1.0.0",      // version
          "main",       // branch
                
          {"game", "space", "indie", "2d"}, // tags
                
          {"/img/server-slot.webp",
           "/img/Tv-bg01.png",
           "/img/Rider.png"}
        },





        {
          "p3",
          "Cool indie game about space",
          "/img/server-slot.webp",
                
          "https://github.com/me/game",
          "https://download-link.com",
                
          "MIT",        // license
          "1.0.0",      // version
          "main",       // branch
                
          {"game", "space", "indie", "2d"}, // tags
                
          {"/img/server-slot.webp",
           "/img/Tv-bg01.png",
           "/img/Rider.png"}
        },








        {
          "p4",
          "Cool indie game about space",
          "/img/server-slot.webp",
                
          "https://github.com/me/game",
          "https://download-link.com",
                
          "MIT",        // license
          "1.0.0",      // version
          "main",       // branch
                
          {"game", "space", "indie", "2d"}, // tags
                
          {"/img/server-slot.webp",
           "/img/Tv-bg01.png",
           "/img/Rider.png"}
        },








        {
          "p5",
          "Cool indie game about space",
          "/img/server-slot.webp",
                
          "https://github.com/me/game",
          "https://download-link.com",
                
          "MIT",        // license
          "1.0.0",      // version
          "main",       // branch
                
          {"game", "space", "indie", "2d"}, // tags
                
          {"/img/server-slot.webp",
           "/img/Tv-bg01.png",
           "/img/Rider.png"}
        }
    };


    file("search.html", project_search_page(proj));


    for (const std::string& s : t){

        file(s, page(
            "Ghgltggamer | Open Source Studio",

            navbar() +

            hero(
                "Open Source Studio for Software, Games & Digital Creation",
                "We build and release free software, games, music, and creative tools for everyone."
            ) +

            stats(
                stat_item("100%", "Open Source") +
                stat_item("Software", "Tools & Utilities") +
                stat_item("Games", "Interactive Projects") +
                stat_item("Media", "Music & Assets")
            ) +

            section("What We Create",
                grid(
                    card("Software", "Lightweight tools and developer utilities.") +
                    card("Games", "Experimental indie and interactive systems.") +
                    card("Music", "Original soundtracks and audio assets.") +
                    card("Assets", "Free textures, images, and design resources.")
                )
            ) +

            section("Principles",
                R"(
<ul>
  <li>Open Source First</li>
  <li>No Restrictions</li>
  <li>Modular Design</li>
  <li>Community Driven</li>
</ul>
                )"
            ) +

            cta(
                "Build With Us",
                "Contributions and collaborations are welcome. Everything is designed to evolve with the community."
            )
        ));
    }

}