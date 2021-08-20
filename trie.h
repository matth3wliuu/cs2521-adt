
#define ALPHABET_SIZE 26

typedef struct node *Trie;

typedef struct node {
    char letter;                        // the current letter 
    Trie children[ALPHABET_SIZE];       // 26 children pointers
    bool endOfWord;                     // is letter a finishing letter
    int data;                           // word frequency (only if finish == true)
} node;

// Create a new Trie 
Trie trieCreate(void);

// Insert a new word into a trie
Trie trieInsert(Trie t, char *word);

// Delete an entire trie
void trieDelete(Trie t);

// Determine if the trie contain a certain word
bool trieSearch(Trie t, char *word);

// Find number of occurrence of a word in a trie
int findNum(Trie t, char *word);

// Print out the whole trie
void printTrie(Trie t)

