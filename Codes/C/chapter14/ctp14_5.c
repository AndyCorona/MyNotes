#include <stdio.h>
#define CSIZE 4
struct name {
    char first[20];
    char last[20];
};


struct student {
    struct name stdname;
    double grade[3];
    double average;
};

void ave(struct student *);
void all_ave(const struct student *);
void myprint(const struct student *);

int main(void){

    int i;
    const struct student *ps;

    struct student students[CSIZE] = {
        [0]={.stdname = {"Andy","Corona"}},
        [1]={.stdname = {"Cjais","Jjska"}},
        [2]={.stdname = {"Ijhsna","Pksian"}},
        [3]={.stdname = {"Psn","Hgabs"}}
    };

    puts("Enter the grade: grade1 grade2 grade3");
    puts("For example: 85.00 67.50 90.60");

    for(i = 0;i< CSIZE;i++){
	
        scanf("%lf %lf %lf",&(students[i].grade[0]),&(students[i].grade[1]),&(students[i].grade[2]));

    }    

    for(i = 0;i< CSIZE;i++){
        
	ave(&students[i]);
	ps = &students[i];
   	myprint(ps);
    }
     
    all_ave(students);
  
  
    return 0;
}


void ave(struct student *s){

    int i;
    double sum;
  
    for(i = 0,sum = 0.0;i<3;i++){

	sum += s->grade[i];

    }
    
    s->average = (sum /3.0);

}

void all_ave(const struct student *s){

    double sum;
    int i;
    for(i = 0,sum = 0.0; i < CSIZE;i++){
	sum += s[i].average;
    }

    printf("Total average: %.2f\n",sum/CSIZE);

}

void myprint(const struct student *s){

    printf("name: %s %s  grade: %.2f %.2f %.2f  average: %.2f\n",s->stdname.last,s->stdname.first,\
    s->grade[0],s->grade[1],s->grade[2],s->average);

}









