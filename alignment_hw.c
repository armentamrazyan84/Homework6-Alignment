#include <stdio.h>

// Structs for Assignment 2 (Field Ordering)
struct StructOrder1 {
    char a;     // 1 byte
    int b;      // 4 bytes (requires 4-byte alignment)
    double c;   // 8 bytes (requires 8-byte alignment)
};

struct StructOrder2 {
    double c;   // 8 bytes
    int b;      // 4 bytes
    char a;     // 1 byte
};

// Structs for Assignment 3 (#pragma pack experiments)
struct DefaultStruct {
    char a;
    int b;
    double c;
};

#pragma pack(1)
struct Packed1Struct {
    char a;
    int b;
    double c;
};
#pragma pack() // Reset packing

#pragma pack(2)
struct Packed2Struct {
    char a;
    int b;
    double c;
};
#pragma pack()

#pragma pack(4)
struct Packed4Struct {
    char a;
    int b;
    double c;
};
#pragma pack()

int main() {
    printf("========================================\n");
    printf("ASSIGNMENT 1: Data Alignment in C\n");
    printf("========================================\n");
    int i_var;
    char c_var;
    double d_var;
    short s_var;

    printf("sizeof(char)   = %zu bytes | Address: %p\n", sizeof(c_var), (void*)&c_var);
    printf("sizeof(short)  = %zu bytes | Address: %p\n", sizeof(s_var), (void*)&s_var);
    printf("sizeof(int)    = %zu bytes | Address: %p\n", sizeof(i_var), (void*)&i_var);
    printf("sizeof(double) = %zu bytes | Address: %p\n", sizeof(d_var), (void*)&d_var);

    printf("\n========================================\n");
    printf("ASSIGNMENT 2: Struct Padding (Field Ordering)\n");
    printf("========================================\n");
    struct StructOrder1 s1;
    struct StructOrder2 s2;

    printf("Order 1 (char a, int b, double):\n");
    printf("  Total Size = %zu bytes\n", sizeof(s1));
    printf("  &a: %p\n  &b: %p\n  &c: %p\n", (void*)&s1.a, (void*)&s1.b, (void*)&s1.c);

    printf("\nOrder 2 (double c, int b, char a):\n");
    printf("  Total Size = %zu bytes\n", sizeof(s2));
    printf("  &c: %p\n  &b: %p\n  &a: %p\n", (void*)&s2.c, (void*)&s2.b, (void*)&s2.a);

    printf("\n========================================\n");
    printf("ASSIGNMENT 3 & BONUS: #pragma pack\n");
    printf("========================================\n");
    struct DefaultStruct def_s;
    struct Packed1Struct p1_s;
    struct Packed2Struct p2_s;
    struct Packed4Struct p4_s;

    printf("Default (No Pack) Size : %zu bytes\n", sizeof(def_s));
    printf("#pragma pack(1) Size    : %zu bytes\n", sizeof(p1_s));
    printf("#pragma pack(2) Size    : %zu bytes\n", sizeof(p2_s));
    printf("#pragma pack(4) Size    : %zu bytes\n", sizeof(p4_s));

    return 0;
}
