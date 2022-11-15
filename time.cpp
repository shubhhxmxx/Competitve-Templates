int addtime(int a,int mins){
 int hrs=mins/60;
 int mns=mins%60;
 int h1=a/100;
 int m1=a%100;
// error(hrs,mns,h1,m1);
 int h2=h1+hrs;
 int m2=m1+mns;
 if(m2>=60){
    h2++;
    m2=m2%60;
 }
 if(h2>=24){
    h2=h2%24;
 }
 return h2*100+m2;


}
