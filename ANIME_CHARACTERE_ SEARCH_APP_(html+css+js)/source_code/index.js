async function fetchData() {
    try {
        const input = document.getElementById('search-input').value;
        const isId = !isNaN(input);
        const endpoint = isId 
            ? `https://api.jikan.moe/v4/characters/${input}`
            : `https://api.jikan.moe/v4/characters?q=${input}`;
    
        const response = await fetch(endpoint);
        if (!response.ok) {
            window.alert("Character not found");
            return; 
        }
        
        const data = await response.json();
        const character = isId ? data.data : data.data[0];
    
        if(character){
            console.log(character);
        const name = document.getElementById("character-name");
        const name_kanji = document.getElementById("character-name_kanji");
        const id = document.getElementById("character-id");
        const description = document.getElementById("character-description");
        const imgPoke = document.getElementById("character-image");

        const characterName = character.name;
        const characterNameKanji = character.name_kanji;
        const characterId = character.mal_id;
        let characterDescription = ""; 
        if(character.about!=null){
         characterDescription = character.about.split('\n').filter(line => line.trim() !== '') .map(line => `• ${line}`).join('<br>') ;
    }
        else{
             characterDescription = "";
        }
        const characterImage = character.images.jpg.image_url;

        name.textContent = characterName;
        name_kanji.textContent=characterNameKanji;
        id.textContent = `#${characterId}`;
        description.innerHTML = characterDescription;
        imgPoke.src = characterImage;

        document.getElementById('character-card').classList.add('visible');}else{
            window.alert("Character not found");
        }
    } catch (error) {
        console.error("Could not fetch resource", error);
    }
}
