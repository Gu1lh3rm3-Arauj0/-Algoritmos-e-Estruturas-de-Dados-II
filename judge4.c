#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char name[16];
  int *projects;
  int numProjects;
  int height;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(char *name, int project) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Erro ao alocar memória.\n");
    exit(1);
  }
  strncpy(newNode->name, name, 15);  
  newNode->name[15] = '\0';
  newNode->projects = (int *)malloc(sizeof(int));
  if (newNode->projects == NULL) {
    fprintf(stderr, "Erro ao alocar memória.\n");
    exit(1);
  }
  newNode->projects[0] = project;
  newNode->numProjects = 1;
  newNode->height = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int height(Node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int balanceFactor(Node *node) {
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

Node *rightRotation(Node *node) {
  Node *newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;
  node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
  newRoot->height = 1 + (height(newRoot->left) > height(newRoot->right) ? height(newRoot->left) : height(newRoot->right));
  return newRoot;
}

Node *leftRotation(Node *node) {
  Node *newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
  // Atualiza a altura dos nós
  node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
  newRoot->height = 1 + (height(newRoot->left) > height(newRoot->right) ? height(newRoot->left) : height(newRoot->right));
  return newRoot;
}

Node *insert(Node *root, char *name, int project) {
  if (root == NULL) {
    return createNode(name, project);
  }

  int cmp = strcmp(name, root->name);
  if (cmp < 0) {
    root->left = insert(root->left, name, project);
  } else if (cmp > 0) {
    root->right = insert(root->right, name, project);
  } else {

    root->projects = (int *)realloc(root->projects, (root->numProjects + 1) * sizeof(int));
    if (root->projects == NULL) {
      fprintf(stderr, "Erro ao alocar memória.\n");
      exit(1);
    }
    root->projects[root->numProjects] = project;
    root->numProjects++;
    return root;
  }

  root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

  int balance = balanceFactor(root);

  if (balance > 1) {
    if (strcmp(name, root->left->name) < 0) {
      return rightRotation(root);
    } else {
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
  if (balance < -1) {
    if (strcmp(name, root->right->name) > 0) {
      return leftRotation(root);
    } else {
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }

  return root;
}

void search(Node *root, char *name) {
  if (root == NULL) {
    printf("0\n");
    return;
  }

  int cmp = strcmp(name, root->name);
  if (cmp < 0) {
    search(root->left, name);
  } else if (cmp > 0) {
    search(root->right, name);
  } else {
    printf("%d", root->height);
    for (int i = 0; i < root->numProjects; i++) {
      printf(" %d", root->projects[i]);
    }
    printf("\n");
  }
}

void freeTree(Node *root) {
  if (root == NULL)
    return;
  freeTree(root->left);
  freeTree(root->right);
  free(root->projects);
  free(root);
}

int main() {
  int op;
  char name[16];
  int project;
  Node *root = NULL;

  while (scanf("%d", &op) != EOF) {
    if (op == 0) break;
    else if (op == 1) {
      scanf("%s %d", name, &project);
      root = insert(root, name, project);
    } else if (op == 2) {
      scanf("%s", name);
      search(root, name);
    } else {
      printf("Operação inválida.\n");
    }
  }

  freeTree(root);

  return 0;
}
