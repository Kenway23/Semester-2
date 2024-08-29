#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struktur untuk linked list
typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;
// Function
void showMenu();
void addDataEnd(Node **head, char *data);
void addDataStart(Node **head, char *data);
void addDataMiddle(Node **head, char *data);
void displayData(Node *head);
int searchData(Node *head, char *data);
void deleteData(Node **head, char *data);
void findMinMax(Node *head);
int main()
{
    Node *head = NULL;
    int choice;
    char item[100];
    while (1)
    {
        showMenu();
        printf("\nPilih menu: ");
        scanf("%d", &choice);
        getchar(); // Hapus karakter baris baru dari buffer input
        switch (choice)
        {
        case 1:
            printf("Masukkan data untuk ditambahkan di akhir: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0'; // Hapus karakter baris baru
            addDataEnd(&head, item);
            printf("Data '%s' telah ditambahkan di akhir.\n", item);
            break;
        case 2:
            printf("Masukkan data untuk ditambahkan di tengah: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0'; // Hapus karakter baris baru
            addDataMiddle(&head, item);
            printf("Data '%s' telah ditambahkan di tengah.\n", item);
            break;
        case 3:
            printf("Masukkan data untuk ditambahkan di awal: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0'; // Hapus karakter baris baru
            addDataStart(&head, item);
            printf("Data '%s' telah ditambahkan di awal.\n", item);
            break;
        case 4:
            displayData(head);
            break;
        case 5:
            printf("Masukkan data yang ingin dicari: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0'; // Hapus karakter baris baru
            if (searchData(head, item))
            {
                printf("Data '%s' ditemukan dalam daftar.\n", item);
            }
            else
            {
                printf("Data '%s' tidak ditemukan dalam daftar.\n", item);
            }
            break;
        case 6:
            printf("Masukkan data yang ingin dihapus: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0'; // Hapus karakter baris baru
            deleteData(&head, item);
            break;
        case 7:
            findMinMax(head);
            break;
        case 8:
            printf("Keluar dari program.\n");
            exit(0);
            break;
        default:
            printf("Pilihan tidak valid, silakan coba lagi.\n");
            break;
        }
    }
    return 0;
}
void showMenu()
{ // Tampilan menu utama
    printf("\n+===============================================================+\n");
    printf("| NAMA : Rifki Muhamad Fauzi                                   |\n");
    printf("| KELAS : TIF 223 PC                                              |\n");
    printf("| NPM : 23552011078                                               |\n");
    printf("+===============================================================+\n");
    printf("| MENU                                                          |\n");
    printf("+===============================================================+\n");
    printf("| 1. Add Data (Akhir) |\n");
    printf("| 2. Add Data (Tengah) |\n");
    printf("| 3. Add Data (Awal) |\n");
    printf("| 4. Tampilkan Data |\n");
    printf("| 5. Cari Data |\n");
    printf("| 6. Hapus Data |\n");
    printf("| 7. Min & Max Nilai |\n");
    printf("| 8. Keluar |\n");
    printf("+===============================================================+\n");
}
void addDataEnd(Node **head, char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *last = *head;
    strcpy(newNode->data, data);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
void addDataStart(Node **head, char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = *head;
    *head = newNode;
}
void addDataMiddle(Node **head, char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    Node *slow = *head;
    Node *fast = (*head)->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    newNode->next = slow->next;
    slow->next = newNode;
}
void displayData(Node *head)
{
    Node *current = head;
    printf("Data saat ini: ");
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
int searchData(Node *head, char *data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void deleteData(Node **head, char *data)
{
    Node *current = *head, *prev = NULL;
    while (current != NULL && strcmp(current->data, data) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Data '%s' tidak ditemukan dalam daftar.\n", data);
        return;
    }
    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    printf("Data '%s' telah dihapus dari daftar.\n", data);
}
void findMinMax(Node *head)
{
    if (head == NULL)
    {
        printf("Daftar kosong, tidak ada nilai minimum atau maksimum.\n");
        return;
    }
    Node *current = head;
    char *min = head->data;
    char *max = head->data;
    while (current != NULL)
    {
        if (strcmp(current->data, min) < 0)
        {
            min = current->data;
        }
        if (strcmp(current->data, max) > 0)
        {
            max = current->data;
        }
        current = current->next;
    }
    printf("Nilai minimum dalam daftar adalah: %s\n", min);
    printf("Nilai maksimum dalam daftar adalah: %s\n", max);
}