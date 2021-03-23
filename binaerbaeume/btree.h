/**
 * @file
 * Dieses Modul stellt eine Struktur zur Repr�sentation von Bin�rb�umen
 * und Funktionen darauf zur Verf�gung.
 *
 * @author  Ulrike Griefahn
 * @date    2019-09-09
 */ 

#ifndef _BTREE_H
#define _BTREE_H
/* ------------------------------------------------------------------------ */


/* ===========================================================================
 * Header-Dateien 
 * ======================================================================== */

#include "btreenode.h"
#include <stdbool.h>

/**
 * Struktur für BinärbuamNodes
 */
typedef struct _BTREE {
    struct _BTREE_NODE *firstNode;

    DESTROY_DATA_FCT destroy_data; /* Fkt. zum Löschen der enthaltenen Daten */
    PRINT_DATA_FCT print_data;     /* Fkt. zum Anzeigen der enthaltenen Daten */
} BTREE;


/* ===========================================================================
 * Funktionsprototypen
 * ======================================================================== */

/**
 * Erzeugt einen neuen Bin�rbaum, dessen Wurzel die �bergebenen Daten 
 * beinhaltet. Im zweiten Parameter wird die Funktion �bergeben, mit der die
 * enthaltenen Daten gel�scht werden k�nnen, im dritten Parameter wird die
 * Funktion �bergeben, mit der die Daten am Bildschirm ausgegeben werden k�nnen.
 * In beiden Parametern kann NULL �bergeben werden, so dass keine Funktionen
 * zum Ausgeben und L�schen der Knotendaten gesetzt sind.
 * 
 * @param data          Daten f�r die Wurzel des neuen Baums
 * @param destroy_data  Funktion, mit der die in den Knoten
 *                      enthaltenen Daten gel�scht werden k�nnen oder NULL
 * @param print_data    Funktion, mit der die in den Knoten
 *                      enthaltenen Daten am Bildschirm ausgegeben werden
 *                      k�nnen oder NULL
 * @return              der neu erzeugte Bin�rbaum
 */
extern BTREE *btree_new(void *data,
                        DESTROY_DATA_FCT destroy_data, 
                        PRINT_DATA_FCT print_data);

/**
 * Erzeugt eine Kopie (deep copy) des �bergebenen Bin�rbaums. Es werden die
 * Struktur des Baums und die Knoten kopiert. Die in den Knoten enthaltenen
 * Daten werden nicht kopiert, sondern nur die Referenz auf sie �bernommen.
 * Im Anschluss an die Funktion verweisen beide B�ume auf dieselben Daten.
 * 
 * Es wird davon ausgegangen, dass tree != NULL ist.
 * 
 * @param tree  Bin�rbaum, der kopiert werden soll
 * @return      die neu erzeugte Kopie
 */
extern BTREE *btree_clone(BTREE *tree);

/**
 * L�scht den �bergebenen Baum, d.h. alle Knoten ausgehend von der Wurzel und 
 * die Struktur f�r den Baum. Wird im zweiten Argument true �bergeben, werden
 * die in den Knoten enthaltenen Daten ebenfalls gel�scht.
 * 
 * @param tree          Baum, der gel�scht werden soll
 * @param destroy_data  true, wenn die Daten gel�scht werden sollen;
 *                      false, sonst
 */
extern void btree_destroy(BTREE **tree, bool destroy_data);

/**
 * Vergleicht die beiden �bergebenen Bin�rb�ume miteinander. Zwei Bin�rb�ume
 * sind gleich, wenn  beide Baeume ab dem Wurzelknoten dieselbe Struktur
 * besitzen und in allen Knoten auf dieselben Daten verweisen. Sie k�nnen sich
 * in den gespeicherten Funktionen unterscheiden.
 *
 * @param tree1     der erste zu vergleichende Bin�rbaum
 * @param tree2     der zweite zu vergleichende Bin�rbaum
 * @return          true, wenn beide B�ume gleich sind, false sonst
 */
extern bool btree_equals(BTREE *tree1, BTREE *tree2);

/**
 * Liefert die Wurzel des �bergebenen Bin�rbaums.
 * 
 * @param tree  Bin�rbaum, dessen Wurzel geliefert werden soll
 * @return      Wurzel des Baums oder NULL, wenn der Baum keinen Wurzelknoten
 *              hat oder kein Baum �bergeben wurde
 */
extern BTREE_NODE *btree_get_root(BTREE *tree);

/**
 * Erzeugt einen neuen Bin�rbaum, dessen Wurzel die �bergebenen Daten 
 * erh�lt. Die neue Wurzel bekommt die Wurzel des Bin�rbaums left als
 * linken Nachfolger und die Wurzel des Bin�rbaums right als rechten 
 * Nachfolger. Der neue Baum erh�lt die Funktionen aus dem Baum, der als 
 * linker Nachfolger angef�gt wird.
 * 
 * Der Speicherbereich der B�ume left und right, jedoch nicht ihrer Knoten 
 * wird freigegeben.
 * 
 * @param left      die erste zu verbindenden B�ume
 * @param right     der zweite der beiden zu verbindenden B�ume
 * @param data      die Daten f�r die Wurzel im neuen Baum
 * @return          der neu erzeugte Baum
 */
extern BTREE *btree_merge(BTREE *left, BTREE *right, void *data);

/**
 * Gibt den Bin�rbaum mit seinen Daten in Preorder-Reihenfolge auf dem 
 * Bildschirm aus.
 *
 * @param tree      Bin�rbaum, der ausgegeben werden soll
 */
extern void btree_print(BTREE *tree);

/* ------------------------------------------------------------------------ */
#endif
