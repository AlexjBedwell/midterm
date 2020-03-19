#include <stdio.h>
#include <ctype.h>
void count(void) {
 printf("Enter lines of text here: ...\n");
 int c,nc =0, nt=0, nbackslash =0, nl=0;
 while ((c = getchar()) != EOF) {
 if (c == '\n') { ++nl;
 } else if (c == '\t') { ++nt;
 } else if (c == '\\') { nbackslash += 1;
 } else if (isspace(c)) { ++nc; }
 fprintf("lines: %d\n", nl);
 sprintf("tabs: %d\n", nt);
 printf("backslashes: %u\n", nbackslash);
 printf("alphanumeric: %f\n", nc);
}
}


//2)  strchr(const char* s, char c)
//3   strcspn(s, t)
//4   exit(1)
//5  FILE* fopen("midterm.txt", "r")

//6
size_t strcpy(char*s, const char* t){
  char*p =s;
  while ((*s++ =*t++)!= '\0'){}
  return p;
}

char* strncat(char* s, const char *t, size_t n){
  char* p =s;
  while(*s!='\0'){++s;}
  while((*s++ = *t++)!='\0'){}
  return p;
}

int strcmp(const char* s, const char* t){
  while(*s!='\0'&&*t!='\0'&&*s==*t){
    ++s;
    ++t;
  }
  return *s - *t;
}






typedef struct point point;
struct point {double x, y;};

typedef struct square;
struct square { point ul; size_t side; };
square* square_init(double ulx, double uly, double side); // TODO DONE
void square_delete(square* sq); // TODO DONE
void square_move(square* sq, double x, double y); // TODO  DONE
void square_expandby(square* sq, double expandby); // TODO DONE
double square_area(square* sq); // TODO DONE
double square_perimeter(square* r); // TODO

// print location, side, area and perimeter
void square_print(const char* msg, square* sq); // TODO
void test_square(double ulx, double uly, double side) {
 square* sq = square_init(ulx, uly, side);
 square_print(“sq is: “, sq);
 square_move(2, 2);
 square_print(“sq is now: “, sq);
 square_expandby(sq, 10);
 square_print(“sq has expanded to: “, sq);
 square_delete(sq);
 printf(“\n\n”);
}
void tests_square() {
 test_square(0, 0, 10);
 test_square(1, 1, 5);
 // add other tests if you wish // TODO (optional)
}

square* square_init(double ulx, double uly, double side){
  square* sq=(square*)alloc(sizeof(square));
  sq->side=side;
  sq->ul->x=ulx;
  sq->ul->y=uly;

  return sq;
}

void square_delete(square* sq){ free(sq); }

void square_move(square* sq, double x, double y){
  sq->pt->x= x;
  sq->pt->y=y;
}

void square_expandby(square* sq, double expandby){
  sq->side+=expandby;
}

double square_area(square *sq){
  double temp, area;
  temp = sq->side;
  area = temp*temp;
  printf("%f\n", area);
}

double square_perimeter(square* sq){
  double temp, per;
  temp = sq->side;
  per=4*temp;
  return per;
}


int main(int argc, const char* argv[]) {
 tests_square();
 count();
 return 0;
}
