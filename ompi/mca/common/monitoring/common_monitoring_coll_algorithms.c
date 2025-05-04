#include "ompi_config.h"
#include "common_monitoring_coll_algorithms.h"
#include "opal/util/output.h"
#include <string.h>
#include <stdlib.h>

// Globale Statistik für alle Kollektiv-Algorithmen
static size_t global_algo_counts[MONITORING_MAX_ALGOS];

// Initialisierung der globalen Zählvariablen
void mca_common_monitoring_coll_algorithms_init(void) {
    memset(global_algo_counts, 0, sizeof(global_algo_counts));
}

// Aufruf bei Verwendung eines bestimmten Algorithmus
void mca_common_monitoring_record_coll_algorithm(int algo_id) {
    if (algo_id < 0 || algo_id >= MONITORING_MAX_ALGOS) return;
    opal_atomic_add_fetch_size_t(&global_algo_counts[algo_id], 1);
}

// Zugriff via MPI_T PVAR
int mca_common_monitoring_get_coll_algorithm(const struct mca_base_pvar_t *pvar,
                                             void *value,
                                             void *obj_handle) {
    (void)pvar;
    (void)obj_handle;
    size_t *out = (size_t *)value;
    memcpy(out, global_algo_counts, sizeof(global_algo_counts));
    return OMPI_SUCCESS;
}


