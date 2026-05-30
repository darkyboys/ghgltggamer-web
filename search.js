let activeTag = null;

const searchBar = document.getElementById("searchBar");
const cards = document.querySelectorAll(".project-card");

function applyFilters(){
    const text = searchBar.value.toLowerCase();

    cards.forEach(card => {
        const content = card.innerText.toLowerCase();

        const matchesText = content.includes(text);
        const matchesTag = !activeTag || content.includes(activeTag.toLowerCase());

        card.style.display = (matchesText && matchesTag) ? "flex" : "none";
    });
}

// text search
searchBar.addEventListener("input", applyFilters);

// tag filter
function filterTag(tag){

    // toggle logic
    activeTag = (activeTag === tag) ? null : tag;

    // reset all buttons
    document.querySelectorAll(".tag-filter").forEach(btn => {
        btn.classList.remove("active");
    });

    // re-apply active state
    if (activeTag !== null){
        document.querySelectorAll(".tag-filter").forEach(btn => {
            if (btn.innerText === activeTag){
                btn.classList.add("active");
            }
        });
    }

    applyFilters();
}

// IMPORTANT: expose globally for onclick=""
window.filterTag = filterTag;