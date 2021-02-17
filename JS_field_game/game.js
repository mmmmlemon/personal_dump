//ВСЯКАЯ ГЛОБАЛЬНАЯ ХРЕНЬ
//переменная, таблица с полем
var gameTable = document.getElementById("gameTable");
var infoField = document.getElementById("infoField");
var scoreTable = document.getElementById("scoreTable");
var playButton = document.getElementById("playButton");
var score1 = document.getElementById("player1Score");
var score2 = document.getElementById("player2Score");


//высота и ширина игрового поля
var gameTableHeight;
var gameTableWidth;

//СОСТОЯНИЯ
//способ заливки, горизонтальный или вертикальный
var fillingState = "horizontal";
//были ли кости брошены на стол
var diceAreOnTable = false;
//текущий игрок
var currentPlayer;

//значение для первого и второго игрального кубика
var firstCube, secondCube;

//цвета полей и кнопки для первого игрока
//цвет стартовой клетки
var cellColorF = "#ff9d42;";
//цвет клеток идущих от стартовой
var blockColorF = "#ffc38c";
//цвет кнопки бросания костей
var buttonColorF = "#ef7e15";

//цвета полей  и кнопки для второго игрока
var cellColorS = "#41bfff;";
var blockColorS = "#8cdeff;";
var buttonColorS = "#14adef;";

//белый цвет
var white = "white";

//цвета для полей для использования, по дефолту белые
var cellColor = white;
var blockColor = white;

//имена игроков
var firstPlayerName, secondPlayerName;

//кубики первого игрока
var fCube1 = document.getElementById("firstDiceP1");
var fCube2 = document.getElementById("firstDiceP2");

//кубики второго игрока
var sCube1 = document.getElementById("secondDiceP1");
var sCube2 = document.getElementById("secondDiceP2");

//доступные для заполнения клетки для первого и второго игрока, массивы
var availableCellsF;
var availableCellsS;

//имитация нажатия кнопки ОК (временно)
document.getElementById('okButton').click();

//загенерить рандомное число в промежутке (используется в definePlayers())
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}

////////////////////////////////////////////////
//ФУНКЦИИ
//если нажата ПКМ то способ заливки меняется с горизонтального на вертикальный или наоборот

//рандомизатор для кубиков, 100 итераций
function randomizer() {
    var num;

    for (var i = 0; i < 100; i++) {
        num = getRandomInt(1, 7);
    }

    return num;
}

//поменять пикчу на кубике
function setImageOnCube(cube, num) {
    if (num == 1) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }

    if (num == 2) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }

    if (num == 3) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }

    if (num == 4) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }

    if (num == 5) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }

    if (num == 6) {
        cube.getElementsByTagName("IMG")[0].src = "src/" + num + ".png";
    }
}

//повернуть рисуемое поле
window.oncontextmenu = function(e) {

    //вычисляем текущее положение мышки
    var x = e.clientX,
        y = e.clientY;
    //по координатам находим клетку таблицы под мышкой 
    var elem = document.elementFromPoint(x, y);

    //записываем клетку в переменную
    var cell = gameTable.rows[elem.parentElement.rowIndex].cells[elem.cellIndex];

    //если текущий режим заполнения горизонтальный
    if (fillingState == "horizontal") {
        //то меняем его на вертикальный
        fillingState = "vertical";

        //стираем нарисованное горизонтальное поле
        eraseSquare(firstCube, secondCube, cell, "horizontal");
        //отрисовываем вертикальное
        drawSquare(firstCube, secondCube, cell, "vertical");

    }
    //тут аналогично
    else {
        fillingState = "horizontal";

        eraseSquare(firstCube, secondCube, cell, "vertical");
        drawSquare(firstCube, secondCube, cell, "horizontal");
    }

    console.log(fillingState);

    //возвращаем false, чтобы не всплывало контекстное меню
    return false;

}

//ф-ция для рисования игрового поля
function drawField() {

    //запиываем ширину и высоту игрового поля
    gameTableHeight = document.getElementById("optionsHeight").value;
    gameTableWidth = document.getElementById("optionsWidth").value;

    //меняем значения если размер больше или мнеьше чем нужно
    if (gameTableHeight > 30) {
        gameTableHeight = 30;
    }

    if (gameTableHeight < 10) {
        gameTableHeight = 10;
    }

    if (gameTableWidth > 40) {
        gameTableWidth = 40;
    }

    if (gameTableWidth < 20) {
        gameTableWidth = 20;
    }

    //в цикле рисуем строки поля, в кол-ве итераций указываем высоту поля из формы
    for (var i = 0; i < gameTableHeight; i++) {
        //вставляем строку и запсиываем её в переменную
        var currentRow = gameTable.insertRow(i);

        //во втором цикле рисуем клетки, в кол-ве итераций указана ширина поля из формы
        for (var ii = 0; ii < gameTableWidth; ii++) {
            //вставляем клетку и записываем её в переменную
            currentCell = currentRow.insertCell(ii);

            //даем клетке класс "cell"
            currentCell.className += "cell notFilled";

            //привязываем к клетке событие onmouseover и ф-цию
            currentCell.onmouseover = function() {
                //нарисовать поле (указываются первый и второй кубик, стартовая клетка и тип заполнения)
                drawSquare(firstCube, secondCube, this, fillingState);
            };

            //привязываем к клетке событие onmouseout и ф-цию
            currentCell.onmouseout = function() {
                //стереть поле, при смене позиции мышки             
                eraseSquare(firstCube, secondCube, this, fillingState);
            };


            $(currentCell).mousedown(function(e) {

                if (e.which == 1) {
                    fillSquare(firstCube, secondCube, this, fillingState);
                }
            });
        }

        //прячем форму за пределами экрана
        document.getElementById("optionsForm").style = "bottom: -99999px;"
    }

    //костыль
    whatthefuckisthis();

    //устанавливаем текущего игрока
    var currentPlayer = definePlayers();


    //показываем кнопку хода для одного из игроков
    getReadytoMove(currentPlayer);

    //добавляем доступные для заполнения клетки для начала игры
    availableCellsF = [gameTable.rows[gameTableHeight - 2].cells[1]];
    availableCellsS = [gameTable.rows[1].cells[gameTableWidth - 2]];
}

//показать доступные для заполнения клетки (берем текущего игрока)
function showAvailableCells(currentPlayer) {
    //переменная для массива клеток
    var cellsArray;

    //если кости были брошены на стол, то будем закрашивать
    if (diceAreOnTable == true) {
        //если текущий игрок 1, то создаем такие настройки
        if (currentPlayer == 1) {
            //в массиве доступных клеток будут клетки первого игрока
            cellsArray = availableCellsF;
            //цвет закращивания
            color = "red";
            //применяемые классы
            style = "cell availForF notFilled";
        } else {
            cellsArray = availableCellsS;
            color = "blue";
            style = "cell availForS notFilled";
        }

        //применяем стиль ко всем клеткам из массива
        for (var i = 0; i < cellsArray.length; i++) {
            cellsArray[i].setAttribute("class", style);
            cellsArray[i].style = "background-color: " + color;
        }
    }
}

//нарисовать поле
function drawSquare(w, h, startCell, mode) {

    //первый парамтер отрисовки
    var firstParam;
    //второй
    var secondParam;

    //если установлен гор. режим
    if (mode == "horizontal") {
        //рисуем сначала по высоте, потом по ширине
        firstParam = h;
        secondParam = w;
    }
    //если вертикальный, то наоборот
    if (mode == "vertical") {
        firstParam = w;
        secondParam = h;
    }
    //индекс стартовой клетки
    var cellIndex = startCell.cellIndex;
    //индекс строки стратовой клетки
    var rowIndex = startCell.parentNode.rowIndex;


    //если у стратовой клетки есть класс availForF, и игрок первый то
    if ($(startCell).hasClass("availForF") && currentPlayer == 1) {
        //цикл для отрисовки, первый параметр... 
        for (var i = 0; i < firstParam; i++) {
            //записываем текущую клетку
            var currEl = gameTable.rows[rowIndex - i].cells[cellIndex];
            //если она не undefined, то красим её
            if (currEl != undefined)
                currEl.style = "background-color: " + cellColor;
            //...второй параметр 
            for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                var currEl = gameTable.rows[rowIndex - i].cells[cellIndex + ii];
                if (currEl != undefined)
                    currEl.style = "background-color: " + blockColor;
            }
        }

    }
    //если у стратовой клетки есть класс availForS, и игрок второй то
    if ($(startCell).hasClass("availForS") && currentPlayer == 2) {
        for (var i = 0; i < firstParam; i++) {
            //записываем текущую клетку
            var currEl = gameTable.rows[rowIndex + i].cells[cellIndex];
            //если она не undefined, то красим её
            if (currEl != undefined)
                currEl.style = "background-color: " + cellColor;
            //...второй параметр 
            for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                var currEl = gameTable.rows[rowIndex + i].cells[cellIndex - ii];
                if (currEl != undefined)
                    currEl.style = "background-color: " + blockColor;
            }
        }

    }


}



//стирание поля
function eraseSquare(w, h, startCell, mode) {
    //все так же как и в рисовании, только красится белым
    var firstParam;
    var secondParam;

    if (mode == "horizontal") {
        firstParam = h;
        secondParam = w;
    }

    if (mode == "vertical") {
        firstParam = w;
        secondParam = h;
    }


    //индекс стартовой клетки
    var cellIndex = startCell.cellIndex;
    //индекс строки стратовой клетки
    var rowIndex = startCell.parentNode.rowIndex;

    //если это заполненное поле, то ничего не делаем
    if ($(startCell).hasClass("filledF")) {
        //do nothing
    }
    //если не заполненные то стираем
    else {
        if ($(startCell).hasClass("availForF") && currentPlayer == 1) {
            for (var i = 0; i < firstParam; i++) {
                //записываем текущую клетку
                var currEl = gameTable.rows[rowIndex - i].cells[cellIndex];
                //если она не undefined, то красим её
                if (currEl != undefined)
                    currEl.style = "background-color: " + white;
                //...второй параметр 
                for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                    var currEl = gameTable.rows[rowIndex - i].cells[cellIndex + ii];
                    if (currEl != undefined)
                        currEl.style = "background-color: " + white;
                }
            }

        }

        if ($(startCell).hasClass("availForS") && currentPlayer == 2) {
            for (var i = 0; i < firstParam; i++) {
                //записываем текущую клетку
                var currEl = gameTable.rows[rowIndex + i].cells[cellIndex];
                //если она не undefined, то красим её
                if (currEl != undefined)
                    currEl.style = "background-color: " + white;
                //...второй параметр 
                for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                    var currEl = gameTable.rows[rowIndex + i].cells[cellIndex - ii];
                    if (currEl != undefined)
                        currEl.style = "background-color: " + white;
                }
            }
        }
    }

    showAvailableCells(currentPlayer);
}


function fillSquare(w, h, startCell, mode) {

    var audio = new Audio("src/click.mp3");
    audio.play();


    //первый парамтер отрисовки
    var firstParam;
    //второй
    var secondParam;

    //если установлен гор. режим
    if (mode == "horizontal") {
        //рисуем сначала по высоте, потом по ширине
        firstParam = h;
        secondParam = w;
    }
    //если вертикальный, то наоборот
    if (mode == "vertical") {
        firstParam = w;
        secondParam = h;
    }
    //индекс стартовой клетки
    var cellIndex = startCell.cellIndex;
    //индекс строки стратовой клетки
    var rowIndex = startCell.parentNode.rowIndex;


    //если у стратовая клетка не заполнена и игрок первый то...
    if ($(startCell).hasClass("notFilled") && currentPlayer == 1) {


        availableCellsF = [];

        //цикл для отрисовки, первый параметр...
        for (var i = 0; i < firstParam; i++) {
            //записываем текущую клетку
            var currEl = gameTable.rows[rowIndex - i].cells[cellIndex];
            currEl.classList.remove("notFilled");
            currEl.classList.remove("availForF");
            //если она не undefined, то красим её
            if (currEl != undefined)
                //currEl.addAtribute("class","filledF");
                currEl.classList.add("filledF");
            currEl.classList.remove("notFilled");
            currEl.style = "background-color: " + buttonColorF;

            //...второй параметр 
            for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                var currEl = gameTable.rows[rowIndex - i].cells[cellIndex + ii];
                if (currEl != undefined)
                    currEl.classList.add("filledF");
                currEl.classList.remove("notFilled");
                currEl.style = "background-color: " + buttonColorF;
            }

        }


       
        findNewAvailCells("filledF", availableCellsF);  
    }
    //..... если игрок второй то...
    if ($(startCell).hasClass("notFilled") && currentPlayer == 2) {

        //цикл для отрисовки, первый параметр...
        for (var i = 0; i < firstParam; i++) {
            //записываем текущую клетку
            var currEl = gameTable.rows[rowIndex + i].cells[cellIndex];
            currEl.classList.remove("notFilled");
            currEl.classList.remove("availForS");

            //если она не undefined, то красим её
            if (currEl != undefined)
                //currEl.addAtribute("class","filledF");
                currEl.classList.add("filledS");
            currEl.classList.remove("notFilled");
            currEl.style = "background-color: " + buttonColorS;
            //...второй параметр 
            for (var ii = 0; ii < secondParam; ii++) { ///тут все то же самое
                var currEl = gameTable.rows[rowIndex + i].cells[cellIndex - ii];
                if (currEl != undefined)
                    currEl.classList.add("filledS");
                currEl.classList.remove("notFilled");
                currEl.style = "background-color: " + buttonColorS;
            }


        }



        findNewAvailCells("filledS", availableCellsS);  
        
    }


    //переходим к следующему игроку
    diceAreOnTable = false;
    playButton.style = "visibility: visible;";
    if(currentPlayer == 1)
    {
        currentPlayer = 2;
        playButton.style = "background-color: " + buttonColorS;
        infoField.innerHTML = "Ходит " + secondPlayerName;
        infoField.style = "color: " + cellColorS;
        fCube1.style = "left: -15%";
        fCube2.style = "left: -15%";

    }
   else
   {
       currentPlayer = 1;
       playButton.style = "background-color: " + buttonColorF;
       infoField.innerHTML = "Ходит " + firstPlayerName;
       infoField.style = "color: " + cellColorF;
       sCube1.style = "right: -15%";
       sCube2.style = "right: -15%";
   }

}

//получить имена игроков и определить рандомно кто будет ходит первым
function definePlayers() {
    //вытаскиваем имена игроков из формы
    firstPlayerName = document.getElementById("optionsP1Name").value;
    secondPlayerName = document.getElementById("optionsP2Name").value;

    //записываем в таблицу с очками
    document.getElementById("player1Field").innerHTML += firstPlayerName;
    document.getElementById("player2Field").innerHTML += secondPlayerName;

    //рандомно определяем кто из игроков будет ходить первый
    var rand = getRandomInt(1, 3);

    //возвращаем рандомного игрока
    return rand;

}

//подготовка к ходу, показываем кнопку
function getReadytoMove(player) {

    //если первый игрок, то красим оранжевым
    if (player == 1) {
        playButton.style = "background-color: " + buttonColorF;
        currentPlayer = 1;
        infoField.innerHTML += "Ходит " + firstPlayerName;
        infoField.style = "color: " + buttonColorF;
        scoreTable.style = "bottom: 9%;";

    }
    //если, второй то синим
    else {
        playButton.style = "background-color: " + buttonColorS;
        currentPlayer = 2;
        infoField.innerHTML += "Ходит " + secondPlayerName;
        infoField.style = "color: " + buttonColorS;
        scoreTable.style = "bottom: 9%;";
    }
}

//кидаем кубики
function throwDice() {

    //рандомно определяем угол наклона кубиков для анимации
    var rotation1 = getRandomInt(40, 90);
    var rotation2 = getRandomInt(40, 90);


    //рандомно получаем результут для первого и второго куба
    var firstNum = randomizer();
    var secondNum = randomizer();

    firstCube = firstNum;
    secondCube = secondNum;

    //аудиоэффект
    var audio = new Audio('src/throw.wav');
    audio.play();


    //если текущий игрок 1, то показываем его кубы
    if (currentPlayer == 1) {
        fCube1.style = "left: 8%; transform: rotate(" + rotation1 + "deg);";
        setImageOnCube(fCube1, firstNum);
        fCube2.style = "left: 8%;  transform: rotate(" + rotation2 + "deg);";
        setImageOnCube(fCube2, secondNum);

        //считаем очки
        var prevScore = score1.innerHTML;
        score1.innerHTML = prevScore * 1.0 + firstNum * secondNum;
    }

    //аналогично для второго
    else {
        sCube1.style = "right: 8%; transform: rotate(" + rotation1 + "deg);";
        setImageOnCube(sCube1, firstNum);
        sCube2.style = "right: 8%;  transform: rotate(" + rotation2 + "deg);";
        setImageOnCube(sCube2, secondNum);

        //считаем очки
        var prevScore = score2.innerHTML;
        score2.innerHTML = prevScore * 1.0 + firstNum * secondNum;
    }

    //кости были брошены на стол
    diceAreOnTable = true;

    playButton.style = "visibility: hidden";

    //включаем отрисовку
    if (currentPlayer == 1) {
        cellColor = cellColorF;
        blockColor = blockColorF;
    } else {
        cellColor = cellColorS;
        blockColor = blockColorS;
    }

    showAvailableCells(currentPlayer);
}

//ищем все заполненные клетки и клетки рядом с ними, в которых можно будет ходить
function findNewAvailCells(filledCells, array)
{
    //получаем все заполнненные текущим игроком клетки
    var cells = document.getElementsByClassName(filledCells);

    //в цикле бегаем по всем клеткам и находим клетки над ними
    for(var i = 0; i < cells.length; i++)
    {
        //записываем текущую клетку
        var currCell = cells[i];
        //клетки над, под, справа и слева от текущей
        var upCell, downCell, rightCell, leftCell;
        //записываем их индексы
        upCell = gameTable.rows[currCell.parentElement.rowIndex-1].cells[currCell.cellIndex];
        downCell = gameTable.rows[currCell.parentElement.rowIndex+1].cells[currCell.cellIndex];
        rightCell = gameTable.rows[currCell.parentElement.rowIndex].cells[currCell.cellIndex+1];
        leftCell = gameTable.rows[currCell.parentElement.rowIndex].cells[currCell.cellIndex-1];

        //здесь дописать низ, лево и право

        //если клетка сверху не заполнена, то записываем её в массив клеток доступных для хода
        if (upCell != undefined && upCell.classList.contains("notFilled"))
        {   
                array.push(upCell);
            
        }
        if (downCell != undefined && downCell.classList.contains("notFilled"))
        {
                array.push(downCell);
            
        }
        if (leftCell != undefined && leftCell.classList.contains("notFilled"))
        {
                array.push(leftCell);
        }
        if (rightCell != undefined && rightCell.classList.contains("notFilled"))
        {
                array.push(rightCell);
        }

}

console.log(array);
}

//КОСТЫЛЬ, убираем классы у крайних клеток
function whatthefuckisthis()
{
    //убираем верх
    for(var i = 0; i < gameTableWidth - 1; i++)
    {
        gameTable.rows[0].cells[i].classList.add("hiddenCell");
        gameTable.rows[0].cells[i].classList.remove("cell");
        gameTable.rows[0].cells[i].classList.remove("notFilled");
    }
    //убираем низ
    for(var i = 0; i < gameTableWidth - 1; i++)
    {
        gameTable.rows[gameTableHeight-1].cells[i].classList.add("hiddenCell");
        gameTable.rows[gameTableHeight-1].cells[i].classList.remove("cell");
        gameTable.rows[gameTableHeight-1].cells[i].classList.remove("notFilled");
    }
     //убираем лево
     for(var i = 0; i < gameTableHeight - 1; i++)
     {
         gameTable.rows[i].cells[0].classList.add("hiddenCell");
         gameTable.rows[i].cells[0].classList.remove("cell");
         gameTable.rows[i].cells[0].classList.remove("notFilled");
     }
       //убираем лево
       for(var i = 0; i < gameTableHeight; i++)
       {
           gameTable.rows[i].cells[gameTableWidth-1].classList.add("hiddenCell");
           gameTable.rows[i].cells[gameTableWidth-1].classList.remove("cell");
           gameTable.rows[i].cells[gameTableWidth-1].classList.remove("notFilled");
       }
 }


