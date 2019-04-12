var a = [2,2,5,7,3,1,9];
var tong = [];
//console.log(a);
for(var i = 0;i<10;i++){
    tong[i]=0;
}
//memset(tong,0,sizeof(a));  C++骚操作
for (var i = 0; i < a.length; i++) {
      tong[a[i]]++;
}
for(var i = 0;i<10;i++){
        for (var j = 0; j < tong[i];j++){
               console.log(i);
        }
}
