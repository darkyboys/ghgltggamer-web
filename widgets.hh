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


#include <unordered_set>
#include    <filesystem>
#include      <iostream>
#include       <fstream>
#include        <string>
#include        <vector>

// Structures
struct ExtraDownload {
    std::string label;
    std::string url;
};


struct Project {
    std::string name;
    std::string description;

    std::string icon;

    std::string repo_url;
    std::string download_url; // optional

    std::string license;
    std::string version;
    std::string branch;

    std::vector<std::string> tags;
    std::vector<std::string> screenshots;
    std::vector<ExtraDownload> extra_downloads;
};



struct Article {
    std::string title;
    std::string description;
    std::string cover_image; // optional

    std::vector<std::string> tags;
};


// Essentials
inline std::string project_schema(const Project& p){

    std::string tags;
    for (size_t i = 0; i < p.tags.size(); i++){
        tags += "\"" + p.tags[i] + "\"";
        if (i + 1 < p.tags.size()) tags += ",";
    }

    return R"(
<script type="application/ld+json">
{
  "@context": "https://schema.org",
  "@type": "SoftwareSourceCode",
  "name": ")" + p.name + R"(",
  "description": ")" + p.description + R"(",
  "codeRepository": ")" + p.repo_url + R"(",
  "programmingLanguage": "C++",
  "version": ")" + p.version + R"(",
  "license": ")" + p.license + R"(",
  "keywords": [)" + tags + R"(]
}
</script>
)";
}



inline std::string article_schema(const Article& a){

    std::string tags;
    for (size_t i = 0; i < a.tags.size(); i++){
        tags += "\"" + a.tags[i] + "\"";
        if (i + 1 < a.tags.size()) tags += ",";
    }

    // std::cout << tags;

    return R"(
<script type="application/ld+json">
{
  "@context": "https://schema.org",
  "@type": "Article",
  "headline": ")" + a.title + R"(",
  "description": ")" + a.description + R"(",
  "keywords": [)" + tags + R"(]
}
</script>
)";
}



inline std::string trim_text(const std::string& text, size_t maxLen = 100){
    if (text.size() <= maxLen) return text;

    std::string cut = text.substr(0, maxLen);

    // avoid cutting mid-word (optional polish)
    size_t lastSpace = cut.find_last_of(' ');
    if (lastSpace != std::string::npos){
        cut = cut.substr(0, lastSpace);
    }

    return cut + "...";
}

// Widgets
std::string page(
    const std::string& title,
    const std::string& description,
    const std::string& content,
    const std::string& schema = "",
    const std::string& canonical = "",
    const std::string& image = ""
){
    std::string urlCanonical = canonical.empty() ? "" :
        "<link rel='canonical' href='" + canonical + "' />";

    std::string ogImage = image.empty() ? "" :
        "<meta property='og:image' content='" + image + "' />";

    std::string twitterImage = image.empty() ? "" :
        "<meta name='twitter:image' content='" + image + "' />";

    return R"(<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>)" + title + R"(</title>

<!-- SEO BASICS -->
<meta name="description" content=")" + description + R"(" />
<meta name="keywords" content="opensource, projects, articles, c++, software" />
<meta name="robots" content="index, follow" />

)" + urlCanonical + R"(

<!-- OPEN GRAPH -->
<meta property="og:title" content=")" + title + R"(" />
<meta property="og:description" content=")" + description + R"(" />
<meta property="og:type" content="website" />
)" + ogImage + R"(

<!-- TWITTER -->
<meta name="twitter:card" content="summary_large_image" />
<meta name="twitter:title" content=")" + title + R"(" />
<meta name="twitter:description" content=")" + description + R"(" />
)" + twitterImage + R"(

<!-- STYLES -->
<link rel="stylesheet" href="/style.css">
<link rel="icon" href="/img/icon.png">
)" + schema + R"(

</head>

<body>
)" + content + R"(
</body>

<script src="/script.js"></script>
</html>)";
}





// Navbar
inline std::string navbar(){
    return R"(
<header class="site-header">
  <nav class="navbar" aria-label="Main navigation">

    <a href="/" class="logo">Ghgltggamer</a>

    <!-- ☰ Mobile toggle -->
    <button class="menu-toggle" aria-label="Open menu">
      ☰
    </button>

    <ul class="nav-links" id="navLinks">
      <li><a href="/">Home</a></li>
      <li><a href="/project">Projects</a></li>
      <li><a href="/donate">Donate</a></li>
      <li><a href="/contact">Contact</a></li>
      <li><a href="/articles">Articles</a></li>
    </ul>

    <a href="/project"><button class="cta-btn">Get Started</button></a>

  </nav>
</header>
    )";
}





inline std::string main_Heading(const std::string& h){
    return std::string("<h1 class='cursive'>" + h + "</h1>");
}






inline std::string html(const std::string& h){
    return h;
}







// ---------------- HERO ----------------
inline std::string hero(const std::string& title, const std::string& subtitle){
    return R"(
<section class="hero">
  <div class="hero-content">
)" + 
    std::string("<h1 class='hero-title'>") + title + "</h1>\n" +
    std::string("<p class='hero-subtitle'>") + subtitle + "</p>\n" +

R"(
    <div class="hero-actions">
      <a href="/project" class="primary-btn">Explore Projects</a>
      <a href="/contact" class="secondary-btn">Collaborate</a>
    </div>
  </div>
</section>
)";
}

// ---------------- STATS ----------------
inline std::string stat_item(const std::string& value, const std::string& label){
    return R"(
<div class="stat">
)" + 
    std::string("<h2>") + value + "</h2>\n" +
    std::string("<p>") + label + "</p>\n" +
R"(
</div>
)";
}

inline std::string stats(const std::string& content){
    return R"(
<section class="stats">
)" + content + R"(
</section>
)";
}

// ---------------- SECTION WRAPPER ----------------
inline std::string section(const std::string& title, const std::string& content){
    return R"(
<section class="section">
)" +
    std::string("<h2>") + title + "</h2>\n" +
    content +
R"(
</section>
)";
}

// ---------------- GRID ----------------
inline std::string card(const std::string& title, const std::string& desc){
    return R"(
<div class="card">
)" +
    std::string("<h3>") + title + "</h3>\n" +
    std::string("<p>") + desc + "</p>\n" +
R"(
</div>
)";
}

inline std::string grid(const std::string& content){
    return R"(
<div class="grid">
)" + content + R"(
</div>
)";
}

// ---------------- CTA ----------------
inline std::string cta(const std::string& title, const std::string& text){
    return R"(
<section class="cta">
)" +
    std::string("<h2>") + title + "</h2>\n" +
    std::string("<p>") + text + "</p>\n" +
R"(
<a href="/contact" class="primary-btn">Get In Touch</a>
</section>
)";
}


inline std::string screenshot_slider(const std::vector<std::string>& images){

    std::string slides;

    for (size_t i = 0; i < images.size(); i++){
        slides += "<img class='slide' data-index='" + std::to_string(i) +
                  "' src='" + images[i] + "' />";
    }

    return R"(
<div class="slider">
  <button onclick="prevSlide();" class="slider-btn">←</button>

  <div class="slides">
    )" + slides + R"(
  </div>

  <button onclick="nextSlide();" class="slider-btn">→</button>
</div>
)";
}


// inline std::string project_page(const Project& p){

//     std::string buttons;

//     // Repository button always
//     buttons += "<a class='secondary-btn' href='" + p.repo_url + "'>Repository</a>";

//     // Download button only if available
//     if (!p.download_url.empty()){
//         buttons =
//             "<a class='primary-btn' href='" + p.download_url + "'>Download</a> " +
//             buttons;
//     }

//     std::string screenshots;
//     if (!p.screenshots.empty()){
//         screenshots = screenshot_slider(p.screenshots);
//     }

//     return R"(
// <main class="project-page">

//   <div class="project-header">
//     <img class="project-icon" src=")" + p.icon + R"(" />

//     <div class="project-meta">
//       <h1>)" + p.name + R"(</h1>
//       <p>)" + p.description + R"(</p>

//       <div class="project-buttons">
//         )" + buttons + R"(
//       </div>
//     </div>
//   </div>

//   <section class="project-media">
//     )" + screenshots + R"(
//   </section>

// </main>
// )";
// }




inline std::string project_card(const Project& p){

    return R"(
<div class="project-card">

  <img src=")" + p.icon + R"(" class="project-card-icon"/>

  <div class="project-card-body">
    <h3>)" + p.name + R"(</h3>
    <p>)" + p.description + R"(</p>

    <div class="card-buttons">
      <a href="/project/)" + p.name + R"(" class="primary-btn">View</a>
    </div>
  </div>

</div>
)";
}




inline std::string tags_ui(const std::vector<std::string>& tags){
    std::string out = "<div class='tags'>";

    for (const auto& t : tags){
        out += "<span class='tag'>" + t + "</span>";
    }

    out += "</div>";
    return out;
}



// ---------------- PROJECT PAGE (FULL GENERATOR) ----------------
inline std::string project_page(const Project& p){

    std::string buttons;

    if (!p.download_url.empty()){
        buttons += "<a class='primary-btn' href='" + p.download_url + "'>Download</a>";
    }

    buttons += "<a class='secondary-btn' href='" + p.repo_url + "'>Repository</a>";

    std::string tags;
    for (const auto& t : p.tags){
        tags += "<span class='tag'>" + t + "</span>";
    }

    std::string extraButtons;

    if (!p.extra_downloads.empty()){
        extraButtons += "<div class='extra-downloads'>";
        for (const auto& d : p.extra_downloads){
            extraButtons += "<a class='secondary-btn' href='" + d.url + "'>" + d.label + "</a>";
        }
        extraButtons += "</div>";
    }

    std::string gallery;
    std::string firstImage = "";

    if (!p.screenshots.empty()){
        gallery = "<div class='gallery'><div class='gallery-track'>";
        for (const auto& img : p.screenshots){
            if (firstImage.empty()) firstImage = img;
            gallery += "<img src='" + img + "' />";
        }
        gallery += "</div></div>";
    }

    std::string content = R"(
)" + navbar() + R"(

<main class="project-page">

  <section class="project-top">

    <img class="project-icon" src=")" + p.icon + R"(" />

    <div class="project-info">

      <h1>)" + p.name + R"(</h1>

      <div class="meta-line">
        <span>Version: )" + p.version + R"(</span>
        <span>License: )" + p.license + R"(</span>
        <span>Branch: )" + p.branch + R"(</span>
      </div>

      <div class="tags">)" + tags + R"(</div>

      <div class="project-buttons">)" + buttons + R"(</div>

      )" + extraButtons + R"(

      <p class="project-desc">)" + p.description + R"(</p>

    </div>

  </section>

  <section class="project-media">
    )" + gallery + R"(
  </section>

</main>
)";

    return page(
        p.name,
        p.description,
        content,
        project_schema(p),
        "/project/" + p.name + "/",
        firstImage
    );
}






inline std::string donate_page(){

    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Donate</title>
<link rel="stylesheet" href="/style.css">
<link rel="icon" href="/img/icon.png">
</head>

<body>

)" + navbar() + R"(

<main class="simple-page">

  <section class="center-card">

    <h1>Support the Project</h1>

    <p>
      If you enjoy my open-source work, you can support development here.
    </p>

    <a class="primary-btn" href="https://paypal.me/fozdtx" target="_blank">
      Donate via PayPal
    </a>

  </section>

</main>

</body>
<script src="/script.js"></script>
</html>
)";
}






inline std::string contact_page(){

    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Contact</title>
<link rel="stylesheet" href="/style.css">
<link rel="icon" href="/img/icon.png">
</head>

<body>

)" + navbar() + R"(

<main class="simple-page">

  <section class="center-card">

    <h1>Contact & Links</h1>

    <p>Connect with me on platforms below:</p>

    <div class="link-list">

      <a class="secondary-btn" href="https://youtube.com/@ghgltggamer" target="_blank">
        YouTube Channel
      </a>

      <a class="secondary-btn" href="https://github.com/darkyboys" target="_blank">
        GitHub Profile
      </a>

    </div>

  </section>

</main>

</body>
<script src="/script.js"></script>
</html>
)";
}








inline std::string project_search_page(const std::vector<Project>& projects){

    // -------------------------
    // COLLECT UNIQUE TAGS
    // -------------------------
    std::unordered_set<std::string> tag_set;

    for (const auto& p : projects){
        for (const auto& t : p.tags){
            tag_set.insert(t);
        }
    }

    // -------------------------
    // TAG FILTER BUTTONS
    // -------------------------
    std::string tagFilters = "<div class='tag-filters'>";

    for (const auto& t : tag_set){
        tagFilters += "<button class='tag-filter' onclick=\"filterTag('" + t + "')\">" + t + "</button>";
    }

    tagFilters += "</div>";

    // -------------------------
    // PROJECT CARDS
    // -------------------------
    std::string cards;

    for (const auto& p : projects){

        std::string tags;
        for (const auto& t : p.tags){
            tags += "<span class='tag small'>" + t + "</span>";
        }

        cards += R"(
<a class="project-card" href="/project/)" + p.name + R"(/">

  <img src=")" + p.icon + R"(" class="project-card-icon"/>

  <div class="project-card-body">
    <h3>)" + p.name + R"(</h3>
    <p>)" + trim_text(p.description, 100) + R"(</p>

    <div class="tags">)" + tags + R"(</div>

  </div>

</a>
)";
    }

    // -------------------------
    // FINAL PAGE
    // -------------------------
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Projects</title>

<link rel="stylesheet" href="/style.css">
<link rel="icon" href="/img/icon.png">
</head>

<body>

)" + navbar() + R"(

<main class="project-search">

  <!-- HEADER -->
  <section class="search-header">

    <h1>Projects</h1>

    )" + tagFilters + R"(

    <input id="searchBar" type="text" placeholder="Search projects..." />

  </section>

  <!-- GRID -->
  <section class="project-grid" id="grid">

    )" + cards + R"(

  </section>

</main>

<script src="/search.js"></script>
<script src="/script.js"></script>

</body>
</html>
)";
}






inline std::string article_page(Article a){

    std::string tags;
    for (const auto& t : a.tags){
        tags += "<span class='tag'>" + t + "</span>";
    }

    std::string imageBlock;
    if (!a.cover_image.empty()){
        imageBlock = "<img class='article-image' src='" + a.cover_image + "' />";
    }

    std::string content = R"(
)" + navbar() + R"(

<main class="article-page">

  <article class="article-container">

    <h1>)" + a.title + R"(</h1>

    <div class="tags">)" + tags + R"(</div>

    )" + imageBlock + R"(

    <p class="article-desc">)" + a.description + R"(</p>

  </article>

</main>
)";

    std::string d;
    bool is_element = false;
    for (char c : a.description){
        if (c == '\n') {continue;}
        if (c == '<') is_element = true;
        if (c == '>') {
            if (d.length() != 0){
                if (d.back() != ' '){
                    d += ' ';
                }
            }
            is_element = false; continue;
        }
        if (not is_element) d += c;
    }

    a.description = d;

    if (d.length() > 300){
        d = d.substr(0, 299);
    }



    return page(
        a.title,
        d,
        content,
        article_schema(a)
    );
}










inline std::string article_search_page(const std::vector<Article>& articles){

    std::unordered_set<std::string> tag_set;

    for (const auto& a : articles){
        for (const auto& t : a.tags){
            tag_set.insert(t);
        }
    }

    std::string tagFilters = "<div class='tag-filters'>";

    for (const auto& t : tag_set){
        tagFilters += "<button class='tag-filter' onclick=\"filterTag('" + t + "')\">" + t + "</button>";
    }

    tagFilters += "</div>";

    std::string cards;

    for (const auto& a : articles){

        std::string tags;
        for (const auto& t : a.tags){
            tags += "<span class='tag small'>" + t + "</span>";
        }

        cards += R"(
<a class="project-card" href="/articles/)" + a.title + R"(/">

  <div class="project-card-body">
    <h3>)" + a.title + R"(</h3>

    <p>)" + trim_text(a.description, 120) + R"(</p>

    <div class="tags">)" + tags + R"(</div>

  </div>

</a>
)";
    }

    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Articles</title>

<link rel="stylesheet" href="/style.css">
<link rel="icon" href="/img/icon.png">
</head>

<body>

)" + navbar() + R"(

<main class="project-search">

  <section class="search-header">

    <h1>Articles</h1>

    )" + tagFilters + R"(

    <input id="searchBar" type="text" placeholder="Search articles..." />

  </section>

  <section class="project-grid">

    )" + cards + R"(

  </section>

</main>

<script src="/search.js"></script>
<script src="/script.js"></script>

</body>
</html>
)";
}