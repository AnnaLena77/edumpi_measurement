#ifndef COLL_MONITORING_ALGO_H
#define COLL_MONITORING_ALGO_H

BEGIN_C_DECLS

#include "ompi_config.h"
#include "opal/mca/base/mca_base_pvar.h"
#include "ompi/mca/common/monitoring/common_monitoring.h"

// Maximal unterstützte Anzahl an Algorithmus-IDs
#define MONITORING_MAX_ALGOS 10

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
                                                           void *obj_handle);

END_C_DECLS

#endif // COLL_MONITORING_ALGO_H

