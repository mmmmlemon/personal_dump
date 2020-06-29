//показываем спиннер, пока грузится информация
$("#div_spin").append(" <div uk-spinner class = 'uk-position-center uk-animation-fade' id = 'spinner'></div>");

//Steam ID профиля
var steam_id = "76561198007577978";
//Ключ от Steam API
var api_key = "B241B15EEA990B034E03D2C240C58AC";


//когда html документ будет готов
$(document).ready(function() {

    //запрос к Steam API
    var steamAPIGamesList = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" + api_key + "A&include_appinfo=1&steamid=" + steam_id + "&format=json";
    var gameslist = "gameslist.json";

    $.getJSON(gameslist, function(json) {
        //если запрос сработает НО
        //если в jsone нет параметра game_count, т.е запрос выдал пустой ответ то делаем это
        console.log(json);
        if (json.response.game_count === undefined) {
            console.log("empty response");
            console.log(json);
            //показываем сообщение об ошибке
            $("#div_spin").append("<span uk-icon='icon: server; ratio: 2' class = 'uk-position-center uk-animation-fade'></span><br> <h3 class='uk-position-center uk-heading-line uk-animation-fade no_api'><span>No connection to Steam API</span></h3>");
            //удаляем спиннер
            $("#spinner").remove();
        } else {
            //если все ок, то грабим json
            //общее кол-во игр в профиле
            var all_games = json.response.game_count;
            //ссылка на параметр games в jsone, через неё будем грабить данные об играх
            var games = json.response.games;

            //добавляем хедеры к таблице с играми
            $("#games_table").append("<thead class = 'uk-animation-slide-top'><tr><th class='uk-text-center'><h4></h4><th class='uk-text-center'><h4>Logo</h4></th><th class=''><h4>Name</h4></th><th class=''><h4>Hours total</h4></th><th><h4>Finished</h4></th></tr></thead>");

            //проходим по всем игорям и вставялем строки в таблицу
            for (var i = 0; i < all_games; i++) {

                //id игры
                var appid = games[i].appid;
                //название jpg-файла с логотипом игры
                var img_logo_url = games[i].img_logo_url;
                //сама ссылка на логотип игры
                var logo = "http://cdn.edgecast.steamstatic.com/steamcommunity/public/images/apps/" + appid + "/" + img_logo_url + ".jpg";

                //иногда у игры нет логотипа, проверяем если его нет, то ставим свой
                if (logo.substr(logo.length - 5) == "/.jpg")
                    logo = "img/no_logo.png";

                //номер игры в списке, плюсуем один т.к счет идет с нуля
                var num = i + 1;

                //добавляем строку в таблицу с информацией об игре
                $("#tbody").append("<tr class = 'uk-animation-slide-bottom'> <td><h4>" + num + "</h4></td><td><img src=" + logo + " alt='" + name + "' class = 'game_icon'></td><td><h4><a href='#modal-container' uk-toggle onmousedown = 'showGameInfo(" + appid + ")'>" + games[i].name + "</a></h4></td><td><h4>" +
                    //кол-во часов сохранено в минутах, делим на 60 и округляем, чтобы поулчить часы
                    Math.round(games[i].playtime_forever / 60) + " hr.</h4></td></tr>");
            }

            //когда все загрузится, удаляем спиннер
            $("#spinner").remove();

        }

    }).fail(function(jqxhr, textStatus, error) {
        //если запрос к API не сработает вообще, то делаем вот это

        //выводим сообщение об ошибке в консольку (хз зачем, но пусть будет)
        var err = textStatus + ", " + error;
        console.log("Request Failed: " + err);

        //показываем сообщение об ошибке
        $("#div_spin").append("<span uk-icon='icon: server; ratio: 2' class = 'uk-position-center uk-animation-fade'></span><br> <h3 class='uk-position-center uk-heading-line uk-animation-fade no_api'><span>No connection to Steam API</span></h3>");
        //удаляем спиннер
        $("#spinner").remove();
    });
});

//показать окно с информацией об игре
function showGameInfo(game_id) {
    //запрос на информацию об игре
    var steamAPIGameInfo = "http://store.steampowered.com/api/appdetails?appids=" + game_id;

    //грабим жсон
    $.getJSON(steamAPIGameInfo, function(json) {

        //ссылка на параметр data
        var gameInfo = json[game_id].data;
        console.log(gameInfo);
        console.log(json);
        
        if (gameInfo === undefined)
            {

                $("#divForGameTitle").html("<h2>Oops. No such game</h2>");
            }
        
        else
            {
        
        //вставляем название игры
        $("#divForGameTitle").append("<h2 class='uk-modal-title uk-animation-slide-top' id = 'game_title'>" + gameInfo.name + "</h2>");

        //в цикле вставляем скриншоты
        for (var i = 0; i < gameInfo.screenshots.length; i++) {
            //"ячейка" для скриншота
            $("#screenSlider").append("<li class='uk-width-1-2 uk-animation-fade'><div class='uk-panel' id ='screen" + i + "'></div></li>");

            //ссылка на скриншот
            var screenUrl = gameInfo.screenshots[i].path_full.substring(0, gameInfo.screenshots[i].path_full.length - 13);

            //сам скриншот, в виде ссылки и картинки внутри
            $("#screen" + i).append("<a class='uk-inline uk-animation-fade imgs' href='" + screenUrl + "'>" +
                "<img src='" + gameInfo.screenshots[i].path_full + "' class = 'imgs'></a>");

        }

        //я не помню что это, но видимо это надо
        $("#preUl").append("<a class='uk-position-center-left uk-position-small uk-hidden-hover ' href='#' uk-slidenav-previous uk-slider-item='previous'></a>" +
            "<a class='uk-position-center-right uk-position-small uk-hidden-hover' href='#' uk-slidenav-next uk-slider-item='next'></a>");

        //вставялем разработчика
        $("#game_dev").html(gameInfo.developers[0]);
        //вставляем издателя
        $("#game_pub").html(gameInfo.publishers[0]);

        //платформы
        var platforms = gameInfo.platforms;

        //если есть платформа X, то вставляем её
        if (platforms.windows === true) {
            $("#platforms").append("Windows");
        }

        if (platforms.linux === true) {
            $("#platforms").append(", Linux");
        }

        if (platforms.mac === true) {
            $("#platforms").append(", Mac");
        }

        //вставялем дату выхода
        $("#release_date").html(gameInfo.release_date.date);

        //вставялем описание игры
        $("#divForDesc").append("<p class = 'uk-animation-fade'>" + gameInfo.about_the_game + "</p>");


        //список жанров
        for (var i = 0; i < gameInfo.genres.length; i++) {
            $("#divForTags").append("<span class='uk-label uk-animation-slide-bottom' id ='tag'>" + gameInfo.genres[i].description + "<b> </b></span>");
        }
                
                $("#info_table").show();
                }
        
        
        
        var bg_url = gameInfo.header_image.substr(0, gameInfo.header_image.length - 13);
        console.log(bg_url);
        
       // document.getElementById("modal_body").style = "background-image: url(" + bg_url + ");";
        

var img = document.createElement('img');
img.setAttribute('src', bg_url)

img.addEventListener('load', function() {
    var vibrant = new Vibrant(img);
    var swatches = vibrant.swatches()
    
    console.log(swatches);
    
    var r = swatches.DarkMuted.rgb[0] + 80;
    var g = swatches.DarkMuted.rgb[1] + 80;
    var b = swatches.DarkMuted.rgb[2] + 80;
   
    document.getElementById("modal_body").style = "background-color: rgba(" + r + "," + g + "," + b + ", 1);";
    
        
    }); });

}

function clearModal() {
    $("#divForGameTitle").html("");
    $("#screenSlider").html("");
    $("#info_table").hide();
    $("#platforms").html("");
    $("#divForDesc").html("");
    $("#divForTags").html("");


}