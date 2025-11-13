#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50

typedef struct patient {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char gender[MAX_NAME_LEN];
    char problem[MAX_NAME_LEN];
    char medicinerequired[MAX_NAME_LEN];
    char phone[MAX_NAME_LEN];
    struct patient *next;
} Patient;

Patient *head = NULL;

void add_patient() {
    Patient *new_patient = (Patient *) malloc(sizeof(Patient));

    // Get user input for patient ID
    printf("\nEnter patient ID           = ");
    scanf("%d", &new_patient->id);

    // Get user input for patient name
    printf("Enter patient name         = ");
    scanf("%s", new_patient->name);

    // Get user input for patient age
    printf("Enter patient age          = ");
    scanf("%d", &new_patient->age);

    // Get user input for patient gender
    printf("Enter patient gender       = ");
    scanf("%s", new_patient->gender);

    // Get user input for patient address
    printf("Enter patient problem      = ");
    scanf("%s", new_patient->problem);

    // Get user input for patient medicine required
    printf("patient's medicine name    = ");
    scanf("%s", new_patient->medicinerequired);


    // Get user input for patient phone number
    printf("Enter patient phone number = ");
    scanf("%s", new_patient->phone);

    new_patient->next = head;
    head = new_patient;
}

Patient *find_patient(int id) {
    Patient *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_patient(Patient *patient) {
    printf("\nID             = %d\n", patient->id);
    printf("Name           = %s\n", patient->name);
    printf("Age            = %d\n", patient->age);
    printf("Gender         = %s\n", patient->gender);
    printf("problem        = %s\n", patient->problem);
    printf("medicine Name  = %s\n", patient->medicinerequired); //////////
    printf("Phone Number   = %s\n", patient->phone);
}

struct Medicine
{
    int id,price,quantity;
    char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11],info[5000];
}
m[100];

void PurchaseMedicine(int number);
void EnterInfoAboutMedicine(int number);
void KnowInfoAboutMedicine(int number);
void AddMedicineinStore(int number,struct Medicine m[]);
void DeleteMedicineStore(int number);
void ChangeMedicineDetails(int number);

//----------------------------------------------------------

int main(int argc, char **argv) {
    int i,j,choice,number=0,c;
    for(i=0; i<100; i++)
    {
        m[i].id=0;
        m[i].price=0;
        m[i].quantity=0;
        strcpy(m[i].Mfg_Date,"");
        strcpy(m[i].Exp_Date,"");
        strcpy(m[i].medicneName,"");
        strcpy(m[i].Company,"");
        strcpy(m[i].info,"");
    }

    do
    {
        printf("\n\n====================================");
        printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("====================================");
        printf("\n[1] - Purchase Medicine\n");
        printf("[2] - Enter Information about a Medicine\n");
        printf("[3] - Medicine Information\n");
        printf("[4] - Add Medicine\n");
        printf("[5] - Delete a Medicine\n");
        printf("[6] - Change Quantity of Medicine\n");
        printf("[7] - Add Patient\n");
        printf("[8] - Display Patient info\n");

        printf("\nEnter any Number = ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
        {
            PurchaseMedicine(number+1);
            break;
        }
        case 2:
        {
            EnterInfoAboutMedicine(number+1);
            break;
        }
        case 3:
        {
            KnowInfoAboutMedicine(number+1);
            break;
        }
//-----------------------------------------------------------
        case 4:
        {
            ++number;
            AddMedicineinStore(number,m);
            break;
        }
        case 5:
        {
            DeleteMedicineStore(number+1);
            break;
        }
        case 6:
        {
            ChangeMedicineDetails(number+1);
            break;
        }
//----------------------------------------------------------------
        case 7:
        {
            add_patient();
            break;
        }


        case 8:
                printf("\nEnter patient ID to search for: ");
                int id;
                scanf("%d", &id);
                Patient *patient = find_patient(id);
                if (patient != NULL) {
                    print_patient(patient);
                } else {
                    printf("**Patient not found**\n");
                }
                break;

        }
        printf("\nTo Continue with other Options Enter 1 Else any other number\n");
        scanf("%d",&c);
    }
    while(c==1);
}

//-----------------------------------------------marge

//1- purchase medicine function
void PurchaseMedicine(int number)
{
    int id,check,i,quantity,flag=0;
    char name[100];
    printf("\nEnter 1 if you know ID / else enter Name of Medicine\n");
    fflush(stdin);
    scanf("%d",&check);
    if(check==1)
    {
        printf("\nEnter Id to purchase Medicine\n");
        fflush(stdin);
        scanf("%d",&id);
        for(i=0; i<number; i++)
        {
            if(m[i].id==id)
            {
                flag=1;
                int c;

                printf("\nThese are the details of Medicine");
                printf("\n____________________________________\n");
                printf("Name               = %s\n",m[i].medicneName);
                printf("Price              = %d\n",m[i].price);
                printf("Available Quantity = %d\n",m[i].quantity);
                printf("Company            = %s\n",m[i].Company);
                printf("Mfg Date           = %s\n",m[i].Mfg_Date);
                printf("Exp Date           = %s\n",m[i].Exp_Date);


                if(strcmp(m[i].info,"")==0)
                {
                    printf("Medicine Review   = Not Available\n");
                }
                else
                {
                    printf("Medicine Review   = Not Available\n");
                }
                printf("\nDo you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
                fflush(stdin);
                scanf("%d",&c);

                if(c==1)
                {
                    printf("\nEnter Quantity to Purchase = ");
                    scanf("%d",&quantity);
                    if(m[i].quantity>quantity)
                    {
                        printf("Total Price to be paid   = %d\n",quantity*m[i].price);
                    }
                    else
                    {
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if(flag==0)
        {
            printf("Entered Id Not Found\n");
        }
    }
    else
    {
        printf("Enter Name to search and Purchase\n");
        fflush(stdin);
        gets(name);
        for(i=0; i<number; i++)
        {
            if(strcmp(m[i].medicneName,name)==0)
            {
                flag=1;
                int c;

                printf("\nThese are the details of Medicine");
                printf("\n____________________________________\n");
                printf("Name               = %s\n",m[i].medicneName);
                printf("Price              = %d\n",m[i].price);
                printf("Available Quantity = %d\n",m[i].quantity);
                printf("Company            = %s\n",m[i].Company);
                printf("Mfg Date           = %s\n",m[i].Mfg_Date);
                printf("Exp Date           = %s\n",m[i].Exp_Date);


                if(strcmp(m[i].info,"")==0)
                {
                    printf("Medicine Review   = Not Available\n");
                }
                else
                {
                    printf("Medicine Review   = %s\n",m[i].info);
                }
                printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
                fflush(stdin);
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\nEnter Quantity to Purchase  = ");
                    scanf("%d",&quantity);
                    if(m[i].quantity>quantity)
                    {
                        printf("Total Price to be paid = %d\n",quantity*m[i].price);
                    }
                    else
                    {
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if(flag==0)
        {
            printf("Entered Name Not Found\n");
        }
    }
}


//2- Enter information about a medicine
void EnterInfoAboutMedicine(int number)
{
    int i,flag=0,c;
    char name[100],info[100];
    printf("Enter Name of the medicine you want to Review or include Info = "); //need to change
    fflush(stdin);
    gets(name);
    for(i=0; i<number; i++)
    {
        if(strcmp(m[i].medicneName,name)==0)
        {
            flag=1;
            printf("\nThese are the details of Medicine");
            printf("\n____________________________________\n");
            printf("Name               = %s\n",m[i].medicneName);
            printf("Price              = %d\n",m[i].price);
            printf("Available Quantity = %d\n",m[i].quantity);
            printf("Company            = %s\n",m[i].Company);
            printf("Mfg Date           = %s\n",m[i].Mfg_Date);
            printf("Exp Date           = %s\n",m[i].Exp_Date);


            if(strcmp(m[i].info,"")!=0)
            {
                printf("Review Already Available!\nIf you want to Add a Review Enter 1 else Any other number\n");
                fflush(stdin);
                scanf("%d",&c);
            }
            else
            {
                printf("Enter review       = ");
                fflush(stdin);
                gets(m[i].info);
            }
            if(c==1)
            {
                printf("Enter review       = ");
                fflush(stdin);
                gets(info);
                strcat(m[i].info,"; ");
                strcat(m[i].info,info);
            }

        }
    }
    if(flag==0)
    {
        printf("Entered Name Not Found\n");
    }
}


//4-Medicine information
void KnowInfoAboutMedicine(int number)
{
    int i,flag=0;
    char name[100];
    printf("Enter Name of the medicine you want to see Review and Info\n");
    fflush(stdin);
    gets(name);
    for(i=0; i<number; i++)
    {
        if(strcmp(m[i].medicneName,name)==0)
        {
            flag=1;
            printf("\nThese are the details of Medicine");
            printf("\n____________________________________\n");
            printf("Name               = %s\n",m[i].medicneName);
            printf("Price              = %d\n",m[i].price);
            printf("Available Quantity = %d\n",m[i].quantity);
            printf("Company            = %s\n",m[i].Company);
            printf("Mfg Date           = %s\n",m[i].Mfg_Date);
            printf("Exp Date           = %s\n",m[i].Exp_Date);

            if(strcmp(m[i].info,"")!=0)
            {
                printf("Review or Info     = %s\n",m[i].info);
            }
            else
            {
                printf("Review or Info=Not Available\n");
            }
        }
    }
    if(flag==0)
    {
        printf("Entered Name Not Found\n");
    }
}


//5- add medicine
void AddMedicineinStore(int number,struct Medicine m[])
{
    char name[100];

    printf("\n\tADD MEDICINE");
    printf("\n-----------------------------\n");
    printf("Enter Medicine Id       = ");
    scanf("%d",&(m[number].id));
    fflush(stdin);

    printf("Enter Medicine Name     = ");
    fflush(stdin);
    gets(name);
    strcpy(m[number].medicneName,name);

    printf("Enter Company Name      = ");
    fflush(stdin);
    gets(m[number].Company);

    printf("Enter Manufactured Date = ");
    fflush(stdin);
    gets(m[number].Mfg_Date);

    printf("Enter Expiry Date       = ");
    fflush(stdin);
    gets(m[number].Exp_Date);

    printf("Enter Quantity          = ");
    fflush(stdin);
    scanf("%d",&(m[number].quantity));

    printf("Enter Price             = ");
    fflush(stdin);
    scanf("%d",&(m[number].price));
    strcpy(m[number].info,"");

    printf("-----------------------------\n");

    printf("\nMedicine with id %d Added Successfully\n",m[number].id);
}

//delete medicine
void DeleteMedicineStore(int number)
{
    int id,i,flag=0,num;
    printf("\nEnter Id to be deleted = ");
    fflush(stdin);
    scanf("%d",&id);
    for(i=0; i<number; i++)
    {
        if(m[i].id==id)
        {
            flag=1;
            m[i].id=0;
            m[i].price=0;
            m[i].quantity=0;
            strcpy(m[i].medicneName,"");
            strcpy(m[i].Company,"");
            strcpy(m[i].Mfg_Date,"");
            strcpy(m[i].Exp_Date,"");
            strcpy(m[i].info,"");
            num=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("***Medicine with %d is Deleted Successfully***\n",id);
    }
}


//7- change  quantity of medicine
void ChangeMedicineDetails(int number)
{
    int id,quantity,choice,c,i;
    printf("\nEnter id to change Details = ");
    scanf("%d",&id);
    for(i=0; i<number; i++)
    {
        if(m[i].id==id && m[i].id!=0)
        {
            do
            {
                printf("\nEnter\n");
                printf("1- Change Quantity\n");
                printf("2- Change Price\n");
                printf("3- Change Name\n");
                printf("4- Change Company\n");
                printf("5- Change Manufaturing Date\n");
                printf("6- Change Expiry Date\n7- Change Info\n\nAny other number to exit = ");


                scanf("%d",&choice);
                if(choice==1)
                {
                    int quantity;
                    printf("\nEnter Quantity to be changed = ");
                    fflush(stdin);
                    scanf("%d",&quantity);
                    m[i].quantity=quantity;
                    printf("Quantity changed Successfully\n");
                }
                if(choice==2)
                {
                    int price;
                    printf("\nEnter Price to be changed = ");
                    fflush(stdin);
                    scanf("%d",&price);
                    m[i].price=price;
                    printf("Price changed Successfully\n");
                }
                if(choice==3)
                {
                    char name[100];
                    printf("\nEnter Name to be changed = ");
                    fflush(stdin);
                    gets(name);
                    strcpy(m[i].medicneName,name);
                    printf("Medicine Name changed Successfully\n");
                }
                if(choice==4)
                {
                    char company[100];
                    printf("\nEnter company to be changed = ");
                    fflush(stdin);
                    gets(company);
                    strcpy(m[i].Company,company);
                    printf("Company changed Successfully\n");
                }
                if(choice==5)
                {
                    char mfg[11];
                    printf("\nEnter Manufacturing date to be changed = ");
                    fflush(stdin);
                    gets(mfg);
                    strcpy(m[i].Mfg_Date,mfg);
                    printf("Manufacturing Date changed Successfully = ");
                }
                if(choice==6)
                {
                    char exp[11];
                    printf("\nEnter Expiry date to be changed = ");
                    fflush(stdin);
                    gets(exp);
                    strcpy(m[i].Exp_Date,exp);
                    printf("Expiry Date changed Successfully\n");
                }
                if(choice==7)
                {
                    char info[100];
                    printf("\nEnter Info to be changed(Less than 100 Characters) = ");
                    fflush(stdin);
                    gets(info);
                    strcpy(m[i].info,info);
                    printf("Info changed Successfully\n");
                }
                if(choice<=0 && choice>7)
                {
                    printf("\nEnter valid Choice\n");
                }
                printf("\nEnter 1 to Change other Details Else any other number\n");
                fflush(stdin);
                scanf("%d",&c);
            }
            while(c==1);

            break;
        }
    }
}
