/*
 * This is a JavaScript Scratchpad.
 *
 * Enter some JavaScript, then Right Click or choose from the Execute Menu:
 * 1. Run to evaluate the selected text (Ctrl+R),
 * 2. Inspect to bring up an Object Inspector on the result (Ctrl+I), or,
 * 3. Display to insert the result in a comment after the selection. (Ctrl+L)
 */

var str=document.getElementsByClassName("tbl-border tbl1")[0].innerHTML
var st=str.match(/>[\s\S]*</g)
//alert(st.toString().length)
st=st.toString().substring(2).trim()
var ans=st[0];
st=st.split('').reverse().join('').substring(1).trim()
// alert(st)
ans=ans+st.substring(0,st.length-1)
document.getElementsByName("string")[0].value=ans;
// alert(ans)