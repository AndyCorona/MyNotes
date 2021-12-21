#include <stdio.h>
#include <string.h>
struct person{

    long int number;
    struct {char first[20];char medium[10];char last[20];};

};


struct person human[5] = {

    { 302039823,{"Dribble","Mho","Flossie" }},
    { 286315272,{"Andy","","Corona"}},
    { 786251672,{"UHkahs","Hsajk","Hsuak"}},
    { 278133221,{"Jusha","Hhsk","Nsaj"}},
    { 172836789,{"Pjashj","Tghsh","Qqian"}}
};


void mprint(struct person);
void nprint(const struct person *);


int main(void){

    int i;
    for(i = 0;i<5;i++){
        const struct person * ps;
        ps = &human[i];
 	mprint(human[i]);
	nprint(ps);

    }        


    return 0;
}


void mprint(struct person h){

    if(strlen(h.medium) == 0)
        printf("%s,%s - %ld\n",h.first,h.last,h.number);
    else
        printf("%s,%s %c.- %ld\n",h.first,h.last,h.medium[0],h.number);

}

void nprint(const struct person * h){

    if(strlen(h->medium) == 0)
        printf("%s,%s - %ld\n",h->first,h->last,h->number);
    else
        printf("%s,%s %c.- %ld\n",h->first,h->last,h->medium[0],h->number);

}
