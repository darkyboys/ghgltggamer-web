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


std::string sitemap =
R"(<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
)";

void add_url(const std::string& url){
    sitemap +=
        "  <url>\n"
        "    <loc>" + url + "</loc>\n"
        "  </url>\n";
};



int main(){

    // Projects
    std::vector <Project> dataset = {
        {
            "Demon Nation Of Realism - 1024x",
            "Demon's Nation Of Realism is a photorealistic Resource Pack Made for minecraft JavaEdition for making the game as realistic as possible while being freely accessible to everyone who want's to enjoy the realism of Minecraft Modding! This resource pack brings the vision of Photorealism With performance to the real life as the Main Resource pack (Base pack) don't comes with POM & PBR, However you can definetly download the POM & PBR Extensions of this resource pack for also free and start enjoying this with POM & PBR Activated!",
            "https://media.forgecdn.net/avatars/thumbnails/1192/999/256/256/638768212867989863.png",
  
            "https://github.com/darkyboys/demon-nation-of-realism/",
            "https://github.com/darkyboys/demon-nation-of-realism/archive/refs/heads/main.zip",
  
            "MIT",        // license
            "Rolling",      // version
            "main",       // branch
  
            {"Mod"}, // tags
  
            {"https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/1.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/4.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/2.png"},


            {
                {"Download via Ads (Support the project ❤️)", "https://darkyboys.github.io/access/apps/Shorten/link/demon-nation-of-realism/"}
            }
        },



        {
            "Demon Nation Of Realism - 512x",
            "Demon's Nation Of Realism is a photorealistic Resource Pack Made for minecraft JavaEdition for making the game as realistic as possible while being freely accessible to everyone who want's to enjoy the realism of Minecraft Modding! This resource pack brings the vision of Photorealism With performance to the real life as the Main Resource pack (Base pack) don't comes with POM & PBR, However you can definetly download the POM & PBR Extensions of this resource pack for also free and start enjoying this with POM & PBR Activated!",
            "https://media.forgecdn.net/avatars/thumbnails/1192/999/256/256/638768212867989863.png",
  
            "https://github.com/darkyboys/demon-nation-of-realism-512x/",
            "https://github.com/darkyboys/demon-nation-of-realism-512x/archive/refs/heads/main.zip",
  
            "MIT",        // license
            "Rolling",      // version
            "main",       // branch
  
            {"Mod"}, // tags
  
            {"https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/1.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/4.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/2.png"},


            {
                {"Download via Ads (Support the project ❤️)", "https://darkyboys.github.io/access/apps/Shorten/link/demon-nation-of-realism-512x/"}
            }
        },





        {
            "Demon Nation Of Realism - 256x",
            "Demon's Nation Of Realism is a photorealistic Resource Pack Made for minecraft JavaEdition for making the game as realistic as possible while being freely accessible to everyone who want's to enjoy the realism of Minecraft Modding! This resource pack brings the vision of Photorealism With performance to the real life as the Main Resource pack (Base pack) don't comes with POM & PBR, However you can definetly download the POM & PBR Extensions of this resource pack for also free and start enjoying this with POM & PBR Activated!",
            "https://media.forgecdn.net/avatars/thumbnails/1192/999/256/256/638768212867989863.png",
  
            "https://github.com/darkyboys/demon-nation-of-realism-256x/",
            "https://github.com/darkyboys/demon-nation-of-realism-256x/archive/refs/heads/main.zip",
  
            "MIT",        // license
            "Rolling",      // version
            "main",       // branch
  
            {"Mod"}, // tags
  
            {"https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/1.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/4.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/2.png"},


            {
                {"Download via Ads (Support the project ❤️)", "https://darkyboys.github.io/access/apps/Shorten/link/demon-nation-of-realism-256x/"}
            }
        },








        {
            "Demon Nation Of Realism - POM",
            "Demon's Nation Of Realism is a photorealistic Resource Pack Made for minecraft JavaEdition for making the game as realistic as possible while being freely accessible to everyone who want's to enjoy the realism of Minecraft Modding! This resource pack brings the vision of Photorealism With performance to the real life as the Main Resource pack (Base pack) don't comes with POM & PBR, However you can definetly download the POM & PBR Extensions of this resource pack for also free and start enjoying this with POM & PBR Activated!",
            "https://media.forgecdn.net/avatars/thumbnails/1192/999/256/256/638768212867989863.png",
  
            "https://github.com/darkyboys/demon-nation-of-realism-pom/",
            "https://github.com/darkyboys/demon-nation-of-realism-pom/archive/refs/heads/main.zip",
  
            "MIT",        // license
            "Rolling",      // version
            "main",       // branch
  
            {"Mod"}, // tags
  
            {"https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/1.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/4.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/2.png"},


            {
                {"Download via Ads (Support the project ❤️)", "https://darkyboys.github.io/access/apps/Shorten/link/demon-nation-of-realism-pom/"}
            }
        },








        {
            "Demon Nation Of Realism - PBR",
            "Demon's Nation Of Realism is a photorealistic Resource Pack Made for minecraft JavaEdition for making the game as realistic as possible while being freely accessible to everyone who want's to enjoy the realism of Minecraft Modding! This resource pack brings the vision of Photorealism With performance to the real life as the Main Resource pack (Base pack) don't comes with POM & PBR, However you can definetly download the POM & PBR Extensions of this resource pack for also free and start enjoying this with POM & PBR Activated!",
            "https://media.forgecdn.net/avatars/thumbnails/1192/999/256/256/638768212867989863.png",
  
            "https://github.com/darkyboys/demon-nation-of-realism-pbr/",
            "https://github.com/darkyboys/demon-nation-of-realism-pbr/archive/refs/heads/main.zip",
  
            "MIT",        // license
            "Rolling",      // version
            "main",       // branch
  
            {"Mod"}, // tags
  
            {"https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/1.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/4.png",
             "https://raw.githubusercontent.com/darkyboys/demon-nation-of-realism/refs/heads/main/img/2.png"},


            {
                {"Download via Ads (Support the project ❤️)", "https://darkyboys.github.io/access/apps/Shorten/link/demon-nation-of-realism-pbr/"}
            }
        }
    };



    std::vector <Article> dataset_articles = {};
    for (const std::string& s : getFilesInDirectory("raw/articles/")){
        std::string content;
        std::string temp;
        std::ifstream ifile("raw/articles/" + s);
        while (std::getline(ifile, temp)) content += temp + '\n';

        dataset_articles.push_back({
            s,
            content,
            "",
            {"Mod", "Introduction"}
        });
    }



    std::filesystem::create_directory("donate");
    std::filesystem::create_directory("project");
    std::filesystem::create_directory("contact");
    std::filesystem::create_directory("articles");
    file("donate/index.html", donate_page());
    file("contact/index.html", contact_page());
    file("articles/index.html", article_search_page(dataset_articles));
    file("project/index.html", project_search_page(dataset));
    // Build all the projects
    for (const Project& p : dataset){
        std::string path = "project/" + p.name;
        std::filesystem::create_directory(path);
        file(path + "/index.html" , project_page(p));
    }

    for (const Article& a : dataset_articles){
        std::string path = "articles/" + a.title;
        std::filesystem::create_directory(path);
        file(path + "/index.html" , article_page(a));
    }



    file("index.html", page(
            "Ghgltggamer | Open Source Studio",
            "A vast digital library for free and open source softwares for everyone",

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