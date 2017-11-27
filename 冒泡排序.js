var a = [2, 2, 5, 7, 3, 1, 9];
var set;
for(var i = 0;i<a.length;i++){
    for(var j=0;j<a.length-1;j++){
        if(a[i]<a[j]){
            set=a[i];
            a[i]=a[j];
            a[j]=set;
        }
    }
}
console.log(a);
