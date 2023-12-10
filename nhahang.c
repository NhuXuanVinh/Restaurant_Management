#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    int id;
    char name[31];
    char description[501];
    float rating;
    char adress[101];
} nhahang_t;
char *strcasestr(const char *str, const char *pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper((unsigned char)*str) == toupper((unsigned char)*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper((unsigned char)str[i]) != toupper((unsigned char)pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}
void nhapthongtin(nhahang_t nh[100],int *n){
    int i;
    printf("Nhap so luong nha hang: ");
    scanf("%d", n);
    if(n>0){
        for(i=0;i<*n;i++){
            nh[i].id=i+1;
            printf("Nhap ten nha hang %d: ", nh[i].id);
            fflush(stdin);
            scanf("%s", &nh[i].name);
            fflush(stdin);
            printf("Nhap mo ta: ");
            scanf("%s", &nh[i].description);
            fflush(stdin);
            printf("Nhap danh gia: ");
            scanf("%f", &nh[i].rating);
            fflush(stdin);
            printf("Nhap dia chi: ");
            scanf("%s", &nh[i].adress);
            fflush(stdin);
        }
    }
    else{
        printf("\nSo luong nha hang khong hop le.");
    }

}
void inthongtin(nhahang_t nh[100],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nNha hang %d", i+1);
        printf("\nName: %[^\n]s", nh[i].name);
        printf("\nDescription: %[^\n]s", nh[i].description);
        printf("\nRating: %.2f", nh[i].rating);
        printf("\nAdress: %s\n", nh[i].adress);
    }
}
void timkiemten(nhahang_t *nh, int n){
    int i;
    int k=0;
    char s[100];
    printf("Nhap ten nha hang: ");
    scanf("%[^\n]s", s);
    fflush(stdin);
    for(i=0;i<n;i++){
        if( strcasecmp(s,nh[i].name) == 0){
            printf("\nNha hang %d", nh[i].id);
            printf("\nName: %s", nh[i].name);
            printf("\nDescription: %s", nh[i].description);
            printf("\nRating: %.2f", nh[i].rating);
            printf("\nAdress: %s\n", nh[i].adress);
            k++;
        }
    }
    if(k==0){
        printf("Khong tim thay nha hang\n");
    }
}

void timkiemmota(nhahang_t *nh, int n){
    int i;
    int k=0;
    char s[500];
    printf("Nhap ten nha hang: ");
    scanf("%[^\n]s", s);
    fflush(stdin);
    for(i=0;i<n;i++){
        if( strcasestr(s,nh[i].name) != NULL){
            printf("\nNha hang %d", nh[i].id);
            printf("\nName: %s", nh[i].name);
            printf("\nDescription: %s", nh[i].description);
            printf("\nRating: %.2f", nh[i].rating);
            printf("\nAdress: %s\n", nh[i].adress);
            k++;
        }
    }
            if(k==0){
            printf("\nKhong tim thay nha hang\n");
                }
}
void sapxep(nhahang_t *nh, int n){
    int i,j;
    nhahang_t tmp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(nh[i].rating<nh[i+1].rating){
                tmp = nh[i];
                nh[i]=nh[i+1];
                nh[i+1]=tmp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("\nNha hang %d", i+1);
        printf("\nName: %s", nh[i].name);
        printf("\nDescription: %s", nh[i].description);
        printf("\nRating: %.2f", nh[i].rating);
        printf("\nAdress: %s\n", nh[i].adress);
    }
}






void main(){
    int n;
    int c=0;
    nhahang_t nh[100];
    while(c!=6){
        printf("1.Nhap thong tin cac nha hang\n");
        printf("2.In thong tin nha hang\n");
        printf("3.Tim nha hang theo ten\n");
        printf("4.Tim nha hang theo mo ta\n");
        printf("5.Sap xep nha hang theo danh gia\n");
        printf("6.Ket thuc\n");
        scanf("%d", &c);
        switch(c){
        case 1:
          nhapthongtin(nh, &n);
          break;
        case 2:
          inthongtin(nh, n);
          break;
        case 3:
            timkiemten(nh, n);
            break;
        case 4:
            timkiemmota(nh, n);
        case 5:
            sapxep(nh, n);
        }
    }

}
