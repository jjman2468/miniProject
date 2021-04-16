typedef struct{
    char name[20]; //제품명
    int weight; //제품 무게
    int price; //제품 가격
    int star; //제품 별점
    int star_num; //제품 별점의 개수
}Product;

int createProduct(Product *p);
//상품목록에 추가할 때 사용할 함수
void readProduct(Product p);
//상품 하나를 읽어올 때 사용할 함수
int updateProduct(Product *p);
//기존에 저장되어 있던 함수를 수정할 때 사용할 함수
void listProduct(Product *p[], int count);
//readProduct를 활용해 다수의 상품들을 나열할 때 사용할 함수, 여러 구조체를 나열해야 하기 때문에 배열 사용
int deleteProduct(Product *p);
//상품목록에 있는 상품중 하나의 상품을 삭제할 때 사용할 함수
void searchProduct(Product *p, int count);
//상품목록에서 특정 상품을 검색할 때 사용할 함수
int loadData(Product *p);
//상품목록을 기존에 저장되어 있는 파일에서 불러오는 함수
void saveData(Product *p, int count);
//상품목록을 별도의 파일에 저장해주는 함수
int selectMenu();
//메뉴창을 띄워주고 몇버인지 선택하는 함수
int selectDataNo (Product *p[], int count);
//상품목록에서 몇번상품을 선택할 것인지 입력받는 함수
