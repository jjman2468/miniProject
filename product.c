#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

int createProduct(Product *p){
    printf("이름은? ");
    scanf("%s", p->name);
    printf("무게는? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("별점은? ");
    scanf("%d", &p->star);
    printf("평가 수는? ");
    scanf("%d", &p->star_num);
    printf("=> 추가됨!\n");
    return 1;
}
//상품목록에 추가할 때 사용할 함수
void readProduct(Product p){
    printf(" %5s ", p.name);
    printf("%4d ", p.weight);
    printf("%4d ", p.price);
    printf("%4d ", p.star);
    printf("%5d \n", p.star_num);
}
//상품 하나를 읽어올 때 사용할 함수
int updateProduct(Product *p){
    printf("상품명은? ");
    scanf("%s", p->name);
    printf("무게는? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("별점은? ");
    scanf("%d", &p->star);
    printf("평가 수는? ");
    scanf("%d", &p->star_num);
    printf("=> 수정성공!\n");
    return 1;
}
//기존에 저장되어 있던 함수를 수정할 때 사용할 함수
void listProduct(Product *p[], int count){
    printf("\nNo 상품명 무게 가격 별점 평가수\n"); 
    for(int i =0; i<count; i++){
    if(p[i]==NULL) continue; 
    printf("%2d", i+1);
    readProduct(*p[i]); 
    }
}
//readProduct를 활용해 다수의 상품들을 나열할 때 사용할 함수, 여러 구조체를 나열해야 하기 때문에 배열 사용
int deleteProduct(Product *p){
    p->weight = -1;
    p->price = -1;
    p->star = -1;
    p->star_num = -1;
    printf("=> 삭제됨!\n");
    return 1;
}
//상품목록에 있는 상품중 하나의 상품을 삭제할 때 사용할 함수
void searchProduct(Product *p, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 상품명?");
    scanf("%s", search);

    printf("\nNo 상품명 무게 가격 별점 평가수\n");
    printf("================================\n");
    for(int i = 0; i <count; i++){
        if(p[i].weight == -1)continue;
        if(strstr(p[i].name, search)){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
//상품목록에서 특정 상품을 검색할 때 사용할 함수
int loadData(Product *p){
    int count = 0,  i = 0;
    FILE *fp;
    fp = fopen("score.txt", "rt");
    if(fp==NULL){
      printf("=>파일 없음\n");
      return 0;
    }
    else{
      for(; i<100; i++){
          fscanf(fp, "%s", p[i].name);
          if(feof(fp))break;
          fscanf(fp, "%d", &p[i].weight);
          fscanf(fp, "%d", &p[i].price);
          fscanf(fp, "%d", &p[i].star);
          fscanf(fp, "%d", &p[i].star_num);
      }
    printf("=> 로딩 성공!\n");
    return i;
    }
    fclose(fp);
}
//상품목록을 기존에 저장되어 있는 파일에서 불러오는 함수
void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("score.txt", "wt");

    for (int i = 0; i<count; i++){
        if(p[i].weight == -1)continue;
        fprintf(fp, "%s %d %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].star, p[i].star_num);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}
//상품목록을 별도의 파일에 저장해주는 함수
int selectMenu(){
    int menu;
    printf("\n*** 상품 관리 ***\n");
    printf("1. 상품조회\n");
    printf("2. 상품추가\n");
    printf("3. 상품수정\n");
    printf("4. 상품삭제\n");
    printf("5. 저장\n");
    printf("6. 상품이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
//메뉴창을 띄워주고 몇번인지 선택하는 함수
int selectDataNo (Product *p[], int count){
    listProduct(p, count);
    int no;
    printf("번호는(취소:0)?");
    scanf("%d", &no);
    return no;
}
//상품목록에서 몇번상품을 선택할 것인지 입력받는 함수
