/*
 * Program2.c
 *
 *  Created on: 9 Feb 2023
 *      Author: trist
 */

#include <stdio.h>

int main()
{
    
    while(1){
        int score;
        printf("Enter score: ");
        scanf("%d", &score);

        if (score<=1){
            printf("Exiting");
            break;
        }

        for(int td2 = 0; td2<(score/8)+1;td2++){
            for(int td1 = 0; td1<(score/7)+1;td1++){
                for(int td = 0; td<(score/6)+1;td++){
                    for(int fg = 0; fg<(score/3)+1;fg++){
                        for(int safety = 0; safety<(score/2)+1;safety++){
                            if(((td2*8)+(td1*7)+(td*6)+(fg*3)+(safety*2))==score){
                                printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td2,td1,td,fg,safety);
                            }
                        }
                    }
                }
            }
        }
    }
    

    
}
