#ifndef IMO_H
#define IMO_H

struct Moment {
    unsigned hours ;
    unsigned minutes;
    unsigned seconds;
};

struct Date {
    unsigned year ;
    unsigned month;
    unsigned day;
};

struct MbonguosseEvent {
    struct Date dateEvent;
    struct Moment momentEvent;
    const char * nameEvent;
};

void printTab(const char * title, struct MbonguosseEvent const * elt, unsigned nbElement);

int minor (void const * a, void const * b);
int major (void const * a, void const * b);
#endif // IMO_H
