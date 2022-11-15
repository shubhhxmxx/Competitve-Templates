// 4 >> 1=2;
// 2 << 1=4;
// uppercase to lower case
ch|= ' ';
// lowercase to uppercase
ch&='_';

// stripping lowest bit num=(num)&(num-1)

// i th bit set for n (n&(1<<i))
int countsetbits(int n){
    int count=0;
    while(x){
        x&=(x-1);
        count++;
    }
    return count;
}
int ispowerof2(int x){
    return (x&&(x&(x-1)));
}
int lowest_set_bit(int num){
    return (num&(-num));
}
long highest_set_bit(ll n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    n=n|(n>>32);
    return (n+1)>>1;
}
