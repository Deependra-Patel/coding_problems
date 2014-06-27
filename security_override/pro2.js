/*
 * This is a JavaScript Scratchpad.
 *
 * Enter some JavaScript, then Right Click or choose from the Execute Menu:
 * 1. Run to evaluate the selected text (Ctrl+R),
 * 2. Inspect to bring up an Object Inspector on the result (Ctrl+I), or,
 * 3. Display to insert the result in a comment after the selection. (Ctrl+L)
 */
var ans="";
var x=document.getElementsByTagName("code")[1].innerHTML;
//alert(x[0]);
x=x.toString();
x=x.substring(1, x.length)
var arr=x.split("<br>");
// alert(arr[0])
for (var i=0; i<arr.length-1; i++){
    var str=arr[i];
    var ind=str.indexOf("@");
    ans+=", "+(i+1).toString()+"-"+ind.toString();
    while(ind!=-1){
        ind=str.indexOf("@", ind+1);
        if(ind!=-1)
           ans+=", "+(i+1).toString()+"-"+ind.toString();       
    }
}
document.getElementsByName("string")[0].value=ans.substring(2, ans.length);
