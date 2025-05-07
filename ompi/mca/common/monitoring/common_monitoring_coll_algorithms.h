#ifndef COLL_MONITORING_ALGO_H
#define COLL_MONITORING_ALGO_H

BEGIN_C_DECLS

#include "ompi_config.h"
#include "opal/mca/base/mca_base_pvar.h"
#include "ompi/mca/common/monitoring/common_monitoring.h"

// Number of operations (details: https://docs.open-mpi.org/en/v5.0.x/tuning-apps/coll-tuned.html)
/* Allgather  = 0
   Allgatherv = 1
   Allreduce  = 2
   Alltoall   = 3
   Alltoallv  = 4
   Alltoallw  = 5 - no algorithms defined (only inter/intra)
   Barrier    = 6
   Bcast      = 7
   Exscan     = 8
   Gather     = 9
   Gatherv    = 10 - not available in tuned/base module
   Reduce     = 11
   Reduce_scatter = 12
   Reduce_scatter_block = 13
   Scan       = 14
   Scatter    = 15
   Scatterv   = 16 - not available in tuned/base module
*/

#define NUM_OPS 16
#define MONITORING_MAX_ALGOS 9 //Bcast has the most (9) different algorithm options

// Zähle einen verwendeten Kollektivalgorithmus
//void record_coll_algorithm(ompi_communicator_t *comm, int algo_id);

// Gib aktuelle Statistik in eine Datei aus
//OMPI_DECLSPEC void flush_algo_data(FILE *pf);

// Setze alle Statistiken zurück
//OMPI_DECLSPEC void reset_algo_data(void);

OMPI_DECLSPEC void mca_common_monitoring_coll_algorithms_init(void);

// Lies aktuelle Statistik (z.B. für MPI_T PVAR-Zugriff)
OMPI_DECLSPEC int mca_common_monitoring_get_coll_algorithm(const struct mca_base_pvar_t *pvar,
                                                           void *value,
                                                           void *obj_handle
                                                           );
OMPI_DECLSPEC void mca_common_monitoring_coll_algorithms_finalize(void);

END_C_DECLS

#endif // COLL_MONITORING_ALGO_H

