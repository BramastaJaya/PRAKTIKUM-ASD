#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidang{
    char tugas[15];
    char posisi_pekerjaan[10];
    int kode_karyawan;
};
struct pekerja{
    struct bidang *pekerjaan;
    char nama_karyawan[20];
    int umur;
};
    
struct tree{
    struct pekerja *karyawan;
    struct tree *left, *right;
};

struct tree *createnode(struct tree *isinode){
    struct tree *nodebaru = (struct tree*)malloc(sizeof(struct tree));
    strcpy(nodebaru->karyawan->nama_karyawan, isinode->karyawan->nama_karyawan);
    nodebaru->left = NULL;
    nodebaru->right = NULL;
    
    return nodebaru;
}
void printtree(struct tree *node){
    printf("%s", node->karyawan->nama_karyawan);
}

int main(){
    struct tree *node;
    
    strcpy(node->karyawan->nama_karyawan,"budi");
    createnode(node);
    printtree(node);
    
    
    
    return 0;
}