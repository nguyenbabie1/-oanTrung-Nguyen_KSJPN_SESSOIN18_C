#include <stdio.h>
#include <string.h>
#include <math.h>  

void Displaymenu();
struct dish{
		int id;
		char name[50];
		int price;
	};
struct dish menu[100]={
       {1, "Pho Bo",50000},
        {2, "Bun Cha",60000},
        {3, "Com Tam",45000},
        {4, "Banh Mi",30000},
        {5, "Goi Cuon",35000}
};
int main(){
	int choice;
	int count =5;
	int temp, found;
	int food;  
	int i,j;
	do{
		Displaymenu();
		printf("\nLua chon cua ban la:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				for(int i=0; i<count; i++){
					printf("Mon an %d:%d\n",i+1,menu[i].id);
					printf("Ten mon an:%s\n",menu[i].name);
					printf("Gia tien:%dVND\n",menu[i].price); 
				}
				break;
			case 2://Them mon an 
			if(count <=5){
				menu[count].id=count +1; 
				printf("Them mon an:");
				fflush(stdin);
				fgets(menu[count].name, sizeof(menu[count].name) , stdin);
				printf("Nhap gia tien:");
				scanf("%d", &menu[count].price);
				count++;
			}
				// In menu 
				for(int i=0; i<count; i++){
					printf("Mon an %d:%d\n",i+1,menu[i].id);
					printf("Ten mon an:%s\n",menu[i].name);
					printf("Gia tien:%dVND\n",menu[i].price); 
				}
				break;
			case 3:// Sua mon an 
				if (count > 0) {
					printf("Sua ten mon an cuoi cung: ");
					fflush(stdin);
					fgets(menu[count - 1].name, sizeof(menu[count - 1].name), stdin);
					menu[count - 1].name[strcspn(menu[count - 1].name, "\n")] = 0;
					printf("Sua gia tien mon an : ");
					scanf("%d", &menu[count - 1].price);
					printf("Cuoi cung da co duoc em.\n");
				} else {
					printf("Khong co mon an nao de sua.\n");
				}
				// In menu 
				for(int i=0; i<count; i++){
					printf("Mon an %d:%d\n",i+1,menu[i].id);
					printf("Ten mon an:%s\n",menu[i].name);
					printf("Gia tien:%dVND\n",menu[i].price); 
				}
				break;
			case 4://Xoa mon an   
			if(count <=5){
				menu[count].id=count -1;
				printf("xoa mon an:");
				fflush(stdin);
				fgets(menu[count].name, sizeof(menu[count].name) , stdin);
				printf("xoa gia tien:");
				scanf("%d", &menu[count].price);
				count--;
			}
				// in menu sau khi add
				for(int i=0; i<count; i++){
					printf("Mon an %d:%d\n",i+1,menu[i].id);
					printf("Ten mon an:%s\n",menu[i].name);
					printf("Gia tien:%dVND\n",menu[i].price); 
				}
				break;
			case 5:// Sap xep tang dan 
				break;
			case 6:
				// Tim kiem em 
				printf("Nhap id mon an can tim: ");
				getchar();
				scanf("%d",&food);
				
			    for(int i = 0; i < count; i++){
			        if(menu[i].id == food){
			            printf("Ten mon an:%s\n",menu[i].name);
						printf("Gia tien:%dVND\n",menu[i].price); 
			            found = 1; 
			            break;
			        }
			    }
			    if(found == 0){
			        printf("Khong tim thay em!!\n", food);
			    }
				break;
			case 7:
				printf("Thoat \n");
				break;
			default:
				printf("Nhap sai roi .Nhap lai khong la cook\n");
		} 
		
	}while(choice !=7);
	return 0;
}

void Displaymenu(){
	printf("\n     ---MENU---\n");
	printf("1.In cac mon an trong menu \n");
	printf("2.Them mot phan tu vao vi tri \n");
	printf("3.Sua mon an cuoi cung \n");
	printf("4.Xoa mot phan tu o vi tri \n");
	printf("5.Sap xep phan tu tang dan \n");
	printf("6.Tim kiem phan tu theo ten nhap vao \n");
	printf("7.Thoat \n");
}

