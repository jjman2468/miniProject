#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
//#define DEBUG

int main(){
#ifdef DEBUG
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    Product *p[100]={ 0, };
    int index=0, count =0;
    int menu;

    count = loadData(*p);
    index = count;

    while(1){
      menu = selectMenu();
      if(menu==0) {
        printf("종료됨!");
        break;
      }
      if(menu ==1||menu==3||menu==4)
        if(count ==0)continue;
    

      if(menu==2) {
        p[index] = (Product *)malloc(sizeof(Product));
        count += createProduct(p[index++]);
      }

      else if (menu==1){
        listProduct(p, index);
      }

      else if(menu==3){
        int no = selectDataNo(p, index);
        if(no>0)
        updateProduct(p[no-1]);
        else  printf("취소됨!\n");
      }
      
      else if(menu==4){
        int no = selectDataNo(p, index);
        if(no==0){
          printf("=> 취소됨!\n");
          continue;
        }
        int deleteok;
        printf("정말로 삭제하시겠습니까?(삭제: 1)");
        scanf("%d", &deleteok);
        if(deleteok==1){
          if(deleteProduct(p[no-1]))count--;
        }
      }
      else if(menu==5){
        saveData(*p, index);
      }
      else if(menu==6){
        searchProduct(*p, index);
      }
    }return 0;
}
