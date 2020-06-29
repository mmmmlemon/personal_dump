function createElem()
{
    var e = document.getElementById("elemSelect");
    var value = e.options[e.selectedIndex].value; 
    
    var className = document.getElementById('className').value;
    var ID = document.getElementById('ID').value;
    
   if(value == 'Button')
       {
           document.getElementById("window").innerHTML = "<button class ='smoothie editable' id = 'editable'>No Text</button>";
       }
}




function changeWidth(val){
    
    document.getElementById('editable').style.width = val+"px";
    

}



function changeHeight(val){
    
    document.getElementById('editable').style.height = val+"px";
    
}


function changeText(val){
    
  
    
    if (val === "")
        {
            val = "No text"
        }
    
      document.getElementById('editable').innerHTML = val;

}




function changeMargin(val, pos){
    
    if (!pos)
        {
    document.getElementById('editable').style.margin = val+"px";
        }
    
    if (pos === 'l')
        {
            document.getElementById('editable').style.marginLeft = val+"px";
        }
    
     if (pos === 'r')
        {
            document.getElementById('editable').style.marginRight = val+"px";
        }
    
     if (pos === 't')
        {
            document.getElementById('editable').style.marginTop = val+"px";
        }
    
     if (pos === 'b')
        {
            document.getElementById('editable').style.marginBottom  = val+"px";
        }

}

function changePadding(val, pos){
    
   if (!pos)
        {
    document.getElementById('editable').style.padding = val+"px";
        }
    
    if (pos === 'l')
        {
            document.getElementById('editable').style.paddingLeft = val+"px";
        }
    
     if (pos === 'r')
        {
            document.getElementById('editable').style.paddingRight = val+"px";
        }
    
     if (pos === 't')
        {
            document.getElementById('editable').style.paddingTop = val+"px";
        }
    
     if (pos === 'b')
        {
            document.getElementById('editable').style.paddingBottom  = val+"px";
        }

}


function changeFontSize(val)
{
    document.getElementById('editable').style.fontSize  = val+"pt";
}


function changeBrdrRad(val, pos){
    
   if (!pos)
        {
    document.getElementById('editable').style.borderRadius = val+"px";
        }
    
    if (pos === 'l')
        {
            document.getElementById('editable').style.paddingLeft = val+"px";
        }
    
     if (pos === 'r')
        {
            document.getElementById('editable').style.paddingRight = val+"px";
        }
    
     if (pos === 't')
        {
            document.getElementById('editable').style.paddingTop = val+"px";
        }
    
     if (pos === 'b')
        {
            document.getElementById('editable').style.paddingBottom  = val+"px";
        }

}


function changeBorderStyle(val)
{
    if(val === "dotted")
        {
            document.getElementById('editable').style.borderStyle = "dotted";
        }
    
     if(val === "dashed")
        {
            document.getElementById('editable').style.borderStyle = "dashed";
        }
}


function changeBrdrWidth(val){
    
    document.getElementById('editable').style.borderWidth = val + "px";
    document.getElementById('editable').style.borderColor = "black";
    
}






