#include "anpages.h"

typedef struct {
  uint64_t count;
  uint64_t pages[0x1fe];
  uint64_t next; // address, not page; first bit = present
} __attribute__((packed)) anpagelist_t;

uint8_t anpages_initialize(anpages_t pages,
                           uint64_t start,
                           uint64_t used,
                           uint64_t total) {
  if (pages->used >= pages->total) return 0;
  
  pages->list = used + start;
  pages->start = start;
  pages->used = used + 1;
  pages->total = total;
  
  // create a new, empty list structure
  anpagelist_t * list = (anpagelist_t *)(pages->list * 0x1000);
  list->count = 0;
  list->next = 0;
  
  return 1;
}

uint64_t anpages_alloc(anpages_t pages) {
  anpagelist_t * list = (anpagelist_t *)(pages->list * 0x1000);
  if (list->count > 0) {
    // grab the last physical page from the list
    return list->pages[--(list->count)];
  } else if (list->next & 1L) {
    uint64_t page = pages->list;
    pages->list = list->next >> 0xc;
    return page;
  } else {
    if (pages->used < pages->total) {
      
    }
  }
}

void anpages_free(anpages_t pages, uint64_t page) {
  
}