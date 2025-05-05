#include "ompi_config.h"
#include "common_monitoring_coll_algorithms.h"
#include "opal/util/output.h"
#include <string.h>
#include <stdlib.h>

// Globale Statistik für alle Kollektiv-Algorithmen
static opal_atomic_size_t* global_algo_counts = NULL; // NUM_OPS ist die Anzahl der verschiedenen kollektivoperationen


// Initialize global counter variable
void mca_common_monitoring_coll_algorithms_init(void) {
    mca_common_monitoring_coll_algorithm_enabled = 1;
    if (global_algo_counts != NULL) return;
    global_algo_counts = (opal_atomic_size_t*)calloc(NUM_OPS * MONITORING_MAX_ALGOS, sizeof(opal_atomic_size_t));
    if (global_algo_counts == NULL) {
        fprintf(stderr, "Fehler bei calloc für global_algo_counts!\n");
        abort();
    }
    //}
}

void mca_common_monitoring_coll_algorithms_finalize(void) {
    mca_common_monitoring_coll_algorithm_enabled = 0;
    if (global_algo_counts != NULL){
        free(global_algo_counts);
        global_algo_counts = NULL;
    }
    return;
}

// Aufruf bei Verwendung eines bestimmten Algorithmus
void mca_common_monitoring_record_coll_algorithm(int op_id, int algo_id) {
    if (op_id < 0 || op_id >= NUM_OPS || algo_id < 0 || algo_id >= MONITORING_MAX_ALGOS) return;
    opal_atomic_add_fetch_size_t(&global_algo_counts[algo_id], 1);
    //printf("Test: %d\n", global_algo_counts[algo_id]);
}

// Zugriff via MPI_T PVAR
int mca_common_monitoring_get_coll_algorithm(const struct mca_base_pvar_t *pvar,
                                             void *value,
                                             void *obj_handle
) {
    ompi_communicator_t *comm = (ompi_communicator_t *) obj_handle;
    int i, comm_size = ompi_comm_size (comm);
    size_t *values = (size_t*) value;

    if(NULL == global_algo_counts){
        return OMPI_ERROR;
    }

    for (i = 0; i < NUM_OPS * MONITORING_MAX_ALGOS ; i++) {
        /*if(global_algo_counts[i] != 0){
            printf("test\n");
        }*/
        values[i] = global_algo_counts[i];
    }
    
    //mca_common_monitoring_coll_algorithms_finalize();

    return OMPI_SUCCESS;
}



