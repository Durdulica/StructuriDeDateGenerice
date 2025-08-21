#ifndef SISTEMTICKETING_H
#define SISTEMTICKETING_H
#include "que.h"

struct Ticket {
    int counter;
    Queue<int>* coadaUrgenta = new Queue<int>;
    Queue<int>* coadaNormala = new Queue<int>;
    Queue<int>* coadaJoasa   = new Queue<int>;

    int capacitateSistem(int capacity) {
        coadaUrgenta->capacity(capacity);
        coadaNormala->capacity(capacity);
        coadaJoasa->capacity(capacity);
    }

    int creeazaTicket(int prioritate) {
        int ticketID = counter++;

        switch (prioritate) {
            case 1: coadaUrgenta->push(ticketID); break;
            case 2: coadaNormala->push(ticketID); break;
            case 3: coadaJoasa -> push(ticketID); break;
            default: return -1;
        }

        return ticketID;
    }

    int procesareTicket() {
        if(!coadaUrgenta->isEmpty()) {
            return coadaUrgenta->pop()->data;
        }
        if(!coadaNormala->isEmpty()) {
            return coadaNormala->pop()->data;
        }
        if(!coadaJoasa->isEmpty()) {
            return coadaJoasa->pop()->data;
        }
        return -1;
    }
};
#endif //SISTEMTICKETING_H
