#include <stdio.h>
#include <assert.h>

const int N_MAJ_COLORS = 5;
const int N_MIN_COLORS = 5;


typedef struct 
{
    char* Maj_Color;
    char* Min_color;
}ColorPair_set;

int Get_Each_ColorPair_set(void);

void printColorMap(int PairN,ColorPair_set ColorPair ) 
{
    printf("%d | %s | %s\n", PairN, ColorPair.Maj_Color, ColorPair.Min_color);
}

int main() {
    int result;
    result = Get_Each_ColorPair_set();
    assert(result==25);
    assert(result == N_MAJ_COLORS*N_MIN_COLORS);
    
   printf("All is well (maybe!)\n");
    return 0;
}

int Get_Each_ColorPair_set(void)
{
    int i = 0,j=0;
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    ColorPair_set ColorPair;


    
    for(i = 0; i < N_MAJ_COLORS; i++) {
         for(j = 0; j < N_MIN_COLORS; j++) {
            ColorPair.Maj_Color = (char*)majorColor[(i * 5 + j)/N_MAJ_COLORS];
            ColorPair.Min_color = (char*)minorColor[j%N_MIN_COLORS];
          printColorMap( (i * 5 + j),  ColorPair);  
        }
        
    }

    return i*j;
}
