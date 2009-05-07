/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_REVOLVER_H
#define IGRAPH_REVOLVER_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Dynamics measurement                               */
/* -------------------------------------------------- */

int igraph_measure_dynamics_idage(const igraph_t *graph,
				  igraph_matrix_t *akl, 
				  igraph_matrix_t *sd, 
				  igraph_matrix_t *no,
				  igraph_matrix_t *cites,
				  const igraph_vector_t *st, igraph_integer_t agebins,
				  igraph_integer_t maxind);
int igraph_measure_dynamics_idage_st(const igraph_t *graph, igraph_vector_t *res,
				     const igraph_matrix_t *akl);
int igraph_measure_dynamics_idage_expected(const igraph_t *graph,
					   igraph_matrix_t *res,
					   const igraph_matrix_t *akl,
					   const igraph_vector_t *st,
					   igraph_integer_t pmaxind);

int igraph_measure_dynamics_idwindowage(const igraph_t *graph, 
					igraph_matrix_t *akl, 
					igraph_matrix_t *sd, 
					const igraph_vector_t *st, 
					igraph_integer_t pagebins,
					igraph_integer_t pmaxind, 
					igraph_integer_t time_window);
int igraph_measure_dynamics_idwindowage_st(const igraph_t *graph, 
					   igraph_vector_t *res,
					   const igraph_matrix_t *akl,
					   igraph_integer_t time_window);

int igraph_measure_dynamics_citedcat_id_age(const igraph_t *graph,
					    igraph_array3_t *adkl,
					    igraph_array3_t *sd,
					    const igraph_vector_t *st,
					    const igraph_vector_t *cats,
					    igraph_integer_t pno_cats,
					    igraph_integer_t pagebins,
					    igraph_integer_t pmaxind);

int igraph_measure_dynamics_citedcat_id_age_st(const igraph_t *graph,
					       igraph_vector_t *res,
					       const igraph_array3_t *adkl,
					       const igraph_vector_t *cats, 
					       igraph_integer_t pno_cats);

int igraph_measure_dynamics_citingcat_id_age(const igraph_t *graph,
					     igraph_array3_t *adkl,
					     igraph_array3_t *sd,
					     const igraph_vector_t *st,
					     const igraph_vector_t *cats,
					     igraph_integer_t pno_cats,
					     igraph_integer_t pagebins,
					     igraph_integer_t pmaxind);
int igraph_measure_dynamics_citingcat_id_age_st(const igraph_t *graph,
						igraph_vector_t *res,
						const igraph_array3_t *adkl,
						const igraph_vector_t *cats,
						igraph_integer_t pno_cats);

int igraph_measure_dynamics_id(const igraph_t *graph,
			       igraph_matrix_t *ak, igraph_matrix_t *sd,
			       igraph_matrix_t *no, igraph_vector_t *cites,
			       igraph_vector_t *debug,
			       igraph_integer_t debugdeg,
			       const igraph_vector_t *st, igraph_integer_t pmaxind);
int igraph_measure_dynamics_id_st(const igraph_t *graph, 
				  igraph_vector_t *res, 
				  const igraph_matrix_t *ak);
int igraph_measure_dynamics_id_expected(const igraph_t *graph,
					igraph_vector_t *res,
					const igraph_vector_t *ak,
					const igraph_vector_t *st,
					igraph_integer_t pmaxind);
int igraph_measure_dynamics_id_expected2(const igraph_t *graph,
					 igraph_vector_t *res,
					 const igraph_vector_t *ak,
					 const igraph_vector_t *st,
					 igraph_integer_t pmaxind);

int igraph_measure_dynamics_d_d(const igraph_t *graph,
				const igraph_vector_t *ntime,
				const igraph_vector_t *etime,
				igraph_integer_t events,
				igraph_matrix_t *akk,
				igraph_matrix_t *sd,
				const igraph_vector_t *st,
				igraph_integer_t pmadeg);

int igraph_measure_dynamics_d_d_st(const igraph_t *graph,
				   const igraph_vector_t *ntime,
				   const igraph_vector_t *etime,
				   const igraph_matrix_t *akk,
				   igraph_integer_t events,
				   igraph_integer_t maxtotaldeg,
				   igraph_vector_t *st);

int igraph_measure_dynamics_idwindow(const igraph_t *graph, 
				     igraph_matrix_t *ak, 
				     igraph_matrix_t *sd,
				     const igraph_vector_t *st,
				     igraph_integer_t pmaxind,
				     igraph_integer_t time_window);

int igraph_measure_dynamics_idwindow_st(const igraph_t *graph,
					igraph_vector_t *res,
					const igraph_matrix_t *ak,
					igraph_integer_t time_window);

int igraph_measure_dynamics_lastcit(const igraph_t *graph, igraph_vector_t *al,
				    igraph_vector_t *sd,
				    igraph_vector_t *no,
				    const igraph_vector_t *st,
				    igraph_integer_t pagebins);
int igraph_measure_dynamics_lastcit_st(const igraph_t *graph, 
				       igraph_vector_t *res,
				       const igraph_vector_t *al);

int igraph_measure_dynamics_age(const igraph_t *graph, 
				igraph_vector_t *al,
				igraph_vector_t *sd,
				igraph_vector_t *no,
				const igraph_vector_t *st,
				igraph_integer_t pagebins);
int igraph_measure_dynamics_age_st(const igraph_t *graph, 
				   igraph_vector_t *res,
				   const igraph_vector_t *al);

int igraph_measure_dynamics_citedcat(const igraph_t *graph, 
				     const igraph_vector_t *cats,
				     igraph_integer_t pnocats,
				     igraph_vector_t *ak, 
				     igraph_vector_t  *sd,
				     igraph_vector_t *no,
				     const igraph_vector_t *st);
int igraph_measure_dynamics_citedcat_st(const igraph_t *graph,
					igraph_vector_t *res,
					const igraph_vector_t *ak,
					const igraph_vector_t *cats,
					igraph_integer_t pnocats);

int igraph_measure_dynamics_citingcat_citedcat(const igraph_t *graph,
					       igraph_matrix_t *agd,
					       igraph_matrix_t *sd,
					       igraph_matrix_t *no,
					       const igraph_vector_t *st,
					       const igraph_vector_t *cats,
					       igraph_integer_t pnocats);
int igraph_measure_dynamics_citingcat_citedcat_st(const igraph_t *graph,
						  igraph_vector_t *res,
						  const igraph_matrix_t *agd,
						  const igraph_vector_t *cats,
						  igraph_integer_t pnocats);

/* -------------------------------------------------- */
/* Network evolution measurement, new implementation  */
/* -------------------------------------------------- */

int igraph_evolver_d(igraph_t *graph,
		     igraph_integer_t nodes,
		     igraph_vector_t *kernel,
		     const igraph_vector_t *outseq,
		     const igraph_vector_t *outdist,
		     igraph_integer_t m,
		     igraph_bool_t directed);

int igraph_revolver_d(const igraph_t *graph,
		     igraph_integer_t niter,
		     igraph_vector_t *kernel,		     
		     igraph_vector_t *sd,
		     igraph_vector_t *norm,
		     igraph_vector_t *cites,
		     igraph_vector_t *expected,
		     igraph_real_t *logprob,
		     igraph_real_t *lognull,
		     igraph_real_t *logmax,
		     const igraph_vector_t *debug,
		     igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_d(const igraph_t *graph,
			 igraph_vector_t *kernel,
			 igraph_vector_t *sd,
			 igraph_vector_t *norm,
			 igraph_vector_t *cites,
			 const igraph_vector_t *debug,
			 igraph_vector_ptr_t *debugres,
			 igraph_real_t *logmax,
			 const igraph_vector_t *st,
			 igraph_integer_t pmaxind);
int igraph_revolver_st_d(const igraph_t *graph,
			igraph_vector_t *st,
			const igraph_vector_t *kernel);
int igraph_revolver_exp_d(const igraph_t *graphm,
			 igraph_vector_t *expected,
			 const igraph_vector_t *kernel,
			 const igraph_vector_t *st,
			 igraph_integer_t pmaxind);
int igraph_revolver_error_d(const igraph_t *graph,
			   const igraph_vector_t *kernel,
			   const igraph_vector_t *st,
			   igraph_integer_t maxind,
			   igraph_real_t *logprob,
			   igraph_real_t *lognull);
int igraph_revolver_error2_d(const igraph_t *graph,
			     const igraph_vector_t *kernel,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);

int igraph_revolver_ad(const igraph_t *graph,
		      igraph_integer_t niter,
		      igraph_integer_t agebins,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_ad(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  igraph_integer_t pmaxind,
			  igraph_integer_t agebins);
int igraph_revolver_st_ad(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel);
int igraph_revolver_exp_ad(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  igraph_integer_t pmaxind,
			  igraph_integer_t agebins);
int igraph_revolver_error_ad(const igraph_t *graph, 
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    igraph_integer_t pmaxind,
			    igraph_integer_t pagebins,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_ad(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_ade(const igraph_t *graph,
		       igraph_integer_t niter,
		       igraph_integer_t agebins,
		       const igraph_vector_t *cats,
		       igraph_array3_t *kernel,
		       igraph_array3_t *sd,
		       igraph_array3_t *norm,
		       igraph_array3_t *cites,
		       igraph_array3_t *expected,
		       igraph_real_t *logprob,
		       igraph_real_t *lognull,
		       igraph_real_t *logmax,
		       const igraph_matrix_t *debug,
		       igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_ade(const igraph_t *graph, 
			   igraph_array3_t *kernel, 
			   igraph_array3_t *sd,
			   igraph_array3_t *norm,
			   igraph_array3_t *cites,
			   const igraph_matrix_t *debug,
			   igraph_vector_ptr_t *debugres,
			   igraph_real_t *logmax,
			   const igraph_vector_t *st,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_integer_t pmaxind,
			   igraph_integer_t pagebind);
int igraph_revolver_st_ade(const igraph_t *graph,
			  igraph_vector_t *st,
			  const igraph_array3_t *kernel,
			  const igraph_vector_t *cats);
int igraph_revolver_exp_ade(const igraph_t *graph, 
			   igraph_array3_t *expected,
			   const igraph_array3_t *kernel,
			   const igraph_vector_t *st,
			   const igraph_vector_t *cats,
			   igraph_integer_t nocats,
			   igraph_integer_t maxdegree,
			   igraph_integer_t agebins);
int igraph_revolver_error_ade(const igraph_t *graph,
			     const igraph_array3_t *kernel,
			     const igraph_vector_t *st,
			     const igraph_vector_t *cats,
			     igraph_integer_t pnocats,
			     igraph_integer_t pmaxdegree,
			     igraph_integer_t pagebins,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);
int igraph_revolver_error2_ade(const igraph_t *graph,
			       const igraph_array3_t *kernel,
			       const igraph_vector_t *cats,
			       igraph_real_t *logprob,
			       igraph_real_t *lognull);

int igraph_revolver_e(const igraph_t *graph,
		     igraph_integer_t niter,
		     const igraph_vector_t *cats,
		     igraph_vector_t *kernel,
		     igraph_vector_t *st,
		     igraph_vector_t *sd,
		     igraph_vector_t *norm,
		     igraph_vector_t *cites,
		     igraph_vector_t *expected,
		     igraph_real_t *logprob,
		     igraph_real_t *lognull,
		     igraph_real_t *logmax,
		     const igraph_vector_t *debug,
		     igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_e(const igraph_t *graph,
			 igraph_vector_t *kernel,
			 igraph_vector_t *sd,
			 igraph_vector_t *norm,
			 igraph_vector_t *cites,
			 const igraph_vector_t *debug,
			 igraph_vector_ptr_t *debugres,
			 igraph_real_t *logmax,
			 const igraph_vector_t *st,
			 const igraph_vector_t *cats,
			 igraph_integer_t pnocats);
int igraph_revolver_st_e(const igraph_t *graph,
			igraph_vector_t *st,
			const igraph_vector_t *kernel,
			const igraph_vector_t *cats);
int igraph_revolver_exp_e(const igraph_t *graph,
			 igraph_vector_t *expected,
			 const igraph_vector_t *kernel,
			 const igraph_vector_t *st,
			 const igraph_vector_t *cats,
			 igraph_integer_t pnocats);
int igraph_revolver_error_e(const igraph_t *graph,
			   const igraph_vector_t *kernel,
			   const igraph_vector_t *st,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_real_t *logprob,
			   igraph_real_t *lognull);
int igraph_revolver_error2_e(const igraph_t *graph,
			     const igraph_vector_t *kernel,
			     const igraph_vector_t *cats,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);

int igraph_revolver_de(const igraph_t *graph,
		      igraph_integer_t niter,
		      const igraph_vector_t *cats,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_de(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_st_de(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 const igraph_vector_t *cats);
int igraph_revolver_exp_de(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_error_de(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *cats,
			    igraph_integer_t pnocats,
			    igraph_integer_t pmaxind,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_de(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_l(const igraph_t *graph,
		     igraph_integer_t niter,
		     igraph_integer_t agebins,
		     igraph_vector_t *kernel,
		     igraph_vector_t *sd,
		     igraph_vector_t *norm,
		     igraph_vector_t *cites,
		     igraph_vector_t *expected,
		     igraph_real_t *logprob,
		     igraph_real_t *lognull,
		     igraph_real_t *logmax,
		     const igraph_vector_t *debug,
		     igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_l(const igraph_t *graph,
			 igraph_vector_t *kernel,
			 igraph_vector_t *sd,
			 igraph_vector_t *norm,
			 igraph_vector_t *cites,
			 const igraph_vector_t *debug,
			 igraph_vector_ptr_t *debugres,
			 igraph_real_t *logmax,
			 const igraph_vector_t *st,
			 igraph_integer_t pagebins);
int igraph_revolver_st_l(const igraph_t *graph,
			igraph_vector_t *st,
			const igraph_vector_t *kernel);
int igraph_revolver_exp_l(const igraph_t *graph,
			 igraph_vector_t *expected,
			 const igraph_vector_t *kernel,
			 const igraph_vector_t *st,
			 igraph_integer_t pagebins);
int igraph_revolver_error_l(const igraph_t *graph,
			   const igraph_vector_t *kernel,
			   const igraph_vector_t *st,
			   igraph_integer_t pagebins,
			   igraph_real_t *logprob,
			   igraph_real_t *lognull);
int igraph_revolver_error2_l(const igraph_t *graph,
			     const igraph_vector_t *kernel,			     
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);

int igraph_revolver_dl(const igraph_t *graph,
		      igraph_integer_t niter,
		      igraph_integer_t agebins,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_dl(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  igraph_integer_t pmaxind,
			  igraph_integer_t pagebins);
int igraph_revolver_st_dl(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel);
int igraph_revolver_exp_dl(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  igraph_integer_t pmaxind,
			  igraph_integer_t pagebins);
int igraph_revolver_error_dl(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    igraph_integer_t pagebins,
			    igraph_integer_t pmaxind,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_dl(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_el(const igraph_t *graph,
		      igraph_integer_t niter,
		      const igraph_vector_t *cats,
		      igraph_integer_t agebins,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_el(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pagebins);
int igraph_revolver_st_el(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 const igraph_vector_t *cats);
int igraph_revolver_exp_el(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pagebins);
int igraph_revolver_error_el(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *cats,
			    igraph_integer_t pnocats,
			    igraph_integer_t pagebins,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_el(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_r(const igraph_t *graph,
		     igraph_integer_t niter,
		     igraph_integer_t window,
		     igraph_vector_t *kernel,
		     igraph_vector_t *sd,
		     igraph_vector_t *norm,
		     igraph_vector_t *cites,
		     igraph_vector_t *expected,
		     igraph_real_t *logprob,
		     igraph_real_t *lognull,
		     igraph_real_t *logmax,
		     const igraph_vector_t *debug,
		     igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_r(const igraph_t *graph,
			 igraph_vector_t *kernel,
			 igraph_vector_t *sd,
			 igraph_vector_t *norm,
			 igraph_vector_t *cites,
			 const igraph_vector_t *debug,
			 igraph_vector_ptr_t *debugres,
			 igraph_real_t *logmax,
			 const igraph_vector_t *st,
			 igraph_integer_t window,
			 igraph_integer_t maxind);
int igraph_revolver_st_r(const igraph_t *graph,
			igraph_vector_t *st,
			const igraph_vector_t *kernel,
			igraph_integer_t window);
int igraph_revolver_exp_r(const igraph_t *graph,
			 igraph_vector_t *expected,
			 const igraph_vector_t *kernel,
			 const igraph_vector_t *st,
			 igraph_integer_t window,
			 igraph_integer_t pmaxind);
int igraph_revolver_error_r(const igraph_t *graph,
			   const igraph_vector_t *kernel,
			   const igraph_vector_t *st,
			   igraph_integer_t window,
			   igraph_integer_t maxind,			   
			   igraph_real_t *logprob,
			   igraph_real_t *lognull);
int igraph_revolver_error2_r(const igraph_t *graph,
			     const igraph_vector_t *kernel,
			     igraph_integer_t window,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);

int igraph_revolver_ar(const igraph_t *graph,
		      igraph_integer_t niter,
		      igraph_integer_t agebins,
		      igraph_integer_t window,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_ar(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  igraph_integer_t pagebins,
			  igraph_integer_t pwindow,
			  igraph_integer_t maxind);
int igraph_revolver_st_ar(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 igraph_integer_t pwindow);
int igraph_revolver_exp_ar(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  igraph_integer_t agebins,
			  igraph_integer_t window,
			  igraph_integer_t pmaxind);
int igraph_revolver_error_ar(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    igraph_integer_t pagebins,
			    igraph_integer_t pwindow,
			    igraph_integer_t maxind,			   
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_ar(const igraph_t *graph, 
			      const igraph_matrix_t *kernel,
			      igraph_integer_t window, 
			      igraph_real_t *logprob, 
			      igraph_real_t *lognull);

int igraph_revolver_di(const igraph_t *graph,
		      igraph_integer_t niter,
		      const igraph_vector_t *cats,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_di(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_st_di(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 const igraph_vector_t *cats);
int igraph_revolver_exp_di(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_error_di(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *cats,
			    igraph_integer_t pnocats,
			    igraph_integer_t pmaxind,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_di(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_adi(const igraph_t *graph,
		       igraph_integer_t niter,
		       igraph_integer_t agebins,
		       const igraph_vector_t *cats,
		       igraph_array3_t *kernel,
		       igraph_array3_t *sd,
		       igraph_array3_t *norm,
		       igraph_array3_t *cites,
		       igraph_array3_t *expected,
		       igraph_real_t *logprob,
		       igraph_real_t *lognull,
		       igraph_real_t *logmax,
		       const igraph_matrix_t *debug,
		       igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_adi(const igraph_t *graph,
			   igraph_array3_t *kernel,
			   igraph_array3_t *sd,
			   igraph_array3_t *norm,
			   igraph_array3_t *cites,
			   const igraph_matrix_t *debug,
			   igraph_vector_ptr_t *debugres,
			   igraph_real_t *logmax,
			   const igraph_vector_t *st,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_integer_t pmaxind,
			   igraph_integer_t pagebins);
int igraph_revolver_st_adi(const igraph_t *graph,
			  igraph_vector_t *st,
			  const igraph_array3_t *kernel,
			  const igraph_vector_t *cats);
int igraph_revolver_exp_adi(const igraph_t *graph,
			   igraph_array3_t *expected,
			   const igraph_array3_t *kernel,
			   const igraph_vector_t *st,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_integer_t pmaxind,
			   igraph_integer_t pagebins);
int igraph_revolver_error_adi(const igraph_t *graph,
			     const igraph_array3_t *kernel,
			     const igraph_vector_t *st,
			     const igraph_vector_t *cats,
			     igraph_integer_t pnocats,
			     igraph_integer_t pmaxind,
			     igraph_integer_t pagebins,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);
int igraph_revolver_error2_adi(const igraph_t *graph,
			       const igraph_array3_t *kernel,
			       const igraph_vector_t *cats,
			       igraph_real_t *logprob,
			       igraph_real_t *lognull);

int igraph_revolver_il(const igraph_t *graph,
		      igraph_integer_t niter,
		      igraph_integer_t agebins,
		      const igraph_vector_t *cats,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_il(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pagebins);
int igraph_revolver_st_il(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 const igraph_vector_t *cats);
int igraph_revolver_exp_il(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  const igraph_vector_t *cats,
			  igraph_integer_t nocats,
			  igraph_integer_t pagebins);
int igraph_revolver_error_il(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *cats,
			    igraph_integer_t nocats,
			    igraph_integer_t pagebins,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_il(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_ir(const igraph_t *graph,
		      igraph_integer_t niter,
		      igraph_integer_t window,
		      const igraph_vector_t *cats,
		      igraph_matrix_t *kernel,
		      igraph_matrix_t *sd,
		      igraph_matrix_t *norm,
		      igraph_matrix_t *cites,
		      igraph_matrix_t *expected,
		      igraph_real_t *logprob,
		      igraph_real_t *lognull,
		      igraph_real_t *logmax,
		      const igraph_matrix_t *debug,
		      igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_ir(const igraph_t *graph,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *sd,
			  igraph_matrix_t *norm,
			  igraph_matrix_t *cites,
			  const igraph_matrix_t *debug,
			  igraph_vector_ptr_t *debugres,
			  igraph_real_t *logmax,
			  const igraph_vector_t *st,
			  igraph_integer_t pwindow,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_st_ir(const igraph_t *graph,
			 igraph_vector_t *st,
			 const igraph_matrix_t *kernel,
			 igraph_integer_t pwindow,
			 const igraph_vector_t *cats);
int igraph_revolver_exp_ir(const igraph_t *graph,
			  igraph_matrix_t *expected,
			  const igraph_matrix_t *kernel,
			  const igraph_vector_t *st,
			  igraph_integer_t pwindow,
			  const igraph_vector_t *cats,
			  igraph_integer_t pnocats,
			  igraph_integer_t pmaxind);
int igraph_revolver_error_ir(const igraph_t *graph,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    igraph_integer_t pwindow,
			    const igraph_vector_t *cats,
			    igraph_integer_t pnocats,
			    igraph_integer_t pmaxind,
			    igraph_real_t *logprob,
			    igraph_real_t *lognull);
int igraph_revolver_error2_ir(const igraph_t *graph,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_integer_t window,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_air(const igraph_t *graph,
		       igraph_integer_t niter,
		       igraph_integer_t window,
		       igraph_integer_t agebins,
		       const igraph_vector_t *cats,
		       igraph_array3_t *kernel,
		       igraph_array3_t *sd,
		       igraph_array3_t *norm,
		       igraph_array3_t *cites,
		       igraph_array3_t *expected,
		       igraph_real_t *logprob,
		       igraph_real_t *lognull,
		       igraph_real_t *logmax,
		       const igraph_matrix_t *debug,
		       igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_air(const igraph_t *graph,
			   igraph_array3_t *kernel,
			   igraph_array3_t *sd,
			   igraph_array3_t *norm,
			   igraph_array3_t *cites,
			   const igraph_matrix_t *debug,
			   igraph_vector_ptr_t *debugres,
			   igraph_real_t *logmax,
			   const igraph_vector_t *st,
			   igraph_integer_t pwindow,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_integer_t pmaxind,
			   igraph_integer_t pagebins);
int igraph_revolver_st_air(const igraph_t *graph,
			  igraph_vector_t *st,
			  const igraph_array3_t *kernel,
			  igraph_integer_t pwindow,
			  const igraph_vector_t *cats);
int igraph_revolver_exp_air(const igraph_t *graph,
			   igraph_array3_t *expected,
			   const igraph_array3_t *kernel,
			   const igraph_vector_t *st,
			   igraph_integer_t pwindow,
			   const igraph_vector_t *cats,
			   igraph_integer_t pnocats,
			   igraph_integer_t pmaxind,
			   igraph_integer_t pagebins);
int igraph_revolver_error_air(const igraph_t *graph,
			     const igraph_array3_t *kernel,
			     const igraph_vector_t *st,
			     igraph_integer_t pwindow,
			     const igraph_vector_t *cats,
			     igraph_integer_t pnocats,
			     igraph_integer_t pmaxind,
			     igraph_integer_t pagebins,
			     igraph_real_t *logprob,
			     igraph_real_t *lognull);
int igraph_revolver_error2_air(const igraph_t *graph,
			       const igraph_array3_t *kernel,
			       const igraph_vector_t *cats,
			       igraph_integer_t window,
			       igraph_real_t *logprob,
			       igraph_real_t *lognull);

/* Should be moved to to types.h? */
typedef struct igraph_lazy_adjedgelist_t {
  const igraph_t *graph;
  igraph_integer_t length;
  igraph_vector_t **adjs;
  igraph_neimode_t mode;
} igraph_lazy_adjedgelist_t;

/* Non-citation networks */

int igraph_revolver_d_d(const igraph_t *graph,
			igraph_integer_t niter,
			const igraph_vector_t *vtime,
			const igraph_vector_t *etime,
			igraph_matrix_t *kernel,
			igraph_matrix_t *sd,
			igraph_matrix_t *norm,
			igraph_matrix_t *cites,
			igraph_matrix_t *expected,
			igraph_real_t *logprob,
			igraph_real_t *lognull,
			const igraph_matrix_t *debug,
			igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_d_d(const igraph_t *graph, 
			    igraph_lazy_adjedgelist_t *adjlist,
			    igraph_matrix_t *kernel,
			    igraph_matrix_t *sd,
			    igraph_matrix_t *norm,
			    igraph_matrix_t *cites,
			    const igraph_matrix_t *debug,
			    igraph_vector_ptr_t *debugres,
			    const igraph_vector_t *st,
			    const igraph_vector_t *vtime,
			    const igraph_vector_t *vtimeidx,
			    const igraph_vector_t *etime,
			    const igraph_vector_t *etimeidx,
			    igraph_integer_t pno_of_events,
			    igraph_integer_t pmaxdegree);
int igraph_revolver_st_d_d(const igraph_t *graph,
			   igraph_lazy_adjedgelist_t *adjlist,
			   igraph_vector_t *st,
			   const igraph_matrix_t *kernel,
			   const igraph_vector_t *vtime,
			   const igraph_vector_t *vtimeidx,
			   const igraph_vector_t *etime,
			   const igraph_vector_t *etimeidx,
			   igraph_integer_t pno_of_events);
int igraph_revolver_exp_d_d(const igraph_t *graph,
			    igraph_lazy_adjedgelist_t *adjlist,
			    igraph_matrix_t *expected,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *vtime,
			    const igraph_vector_t *vtimeidx,
			    const igraph_vector_t *etime,
			    const igraph_vector_t *etimeidx,
			    igraph_integer_t pno_of_events,
			    igraph_integer_t pmaxdegree);
int igraph_revolver_error_d_d(const igraph_t *graph,
			      igraph_lazy_adjedgelist_t *adjlist,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *st,
			      const igraph_vector_t *vtime,
			      const igraph_vector_t *vtimeidx,
			      const igraph_vector_t *etime,
			      const igraph_vector_t *etimeidx,
			      igraph_integer_t pno_of_events,
			      igraph_integer_t pmaxdegree, 
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

int igraph_revolver_p_p(const igraph_t *graph,
			igraph_integer_t niter,
			const igraph_vector_t *vtime,
			const igraph_vector_t *etime,
			const igraph_vector_t *authors,
			const igraph_vector_t *eventsizes,
			igraph_matrix_t *kernel,
			igraph_matrix_t *sd,
			igraph_matrix_t *norm,
			igraph_matrix_t *cites,
			igraph_matrix_t *expected,
			igraph_real_t *logprob,
			igraph_real_t *lognull,
			const igraph_matrix_t *debug,
			igraph_vector_ptr_t *debugres);
int igraph_revolver_mes_p_p(const igraph_t *graph,
			    igraph_lazy_adjedgelist_t *adjlist,
			    igraph_matrix_t *kernel,
			    igraph_matrix_t *sd,
			    igraph_matrix_t *norm,
			    igraph_matrix_t *cites,
			    const igraph_matrix_t *debug,
			    igraph_vector_ptr_t *debugres,
			    const igraph_vector_t *st,
			    const igraph_vector_t *vtime,
			    const igraph_vector_t *vtimeidx,
			    const igraph_vector_t *etime,
			    const igraph_vector_t *etimeidx,
			    igraph_integer_t pno_of_events,
			    const igraph_vector_t *authors,
			    const igraph_vector_t *eventsizes,
			    igraph_integer_t pmaxpapers);
int igraph_revolver_st_p_p(const igraph_t *graph,
			   igraph_lazy_adjedgelist_t *adjlist,
			   igraph_vector_t *st,
			   const igraph_matrix_t *kernel,
			   const igraph_vector_t *vtime,
			   const igraph_vector_t *vtimeidx,
			   const igraph_vector_t *etime,
			   const igraph_vector_t *etimeidx,
			   igraph_integer_t pno_of_events,
			   const igraph_vector_t *authors,
			   const igraph_vector_t *eventsizes,
			   igraph_integer_t pmaxpapers);
int igraph_revolver_exp_p_p(const igraph_t *graph,
			    igraph_lazy_adjedgelist_t *adjlist,
			    igraph_matrix_t *expected,
			    const igraph_matrix_t *kernel,
			    const igraph_vector_t *st,
			    const igraph_vector_t *vtime,
			    const igraph_vector_t *vtimeidx,
			    const igraph_vector_t *etime,
			    const igraph_vector_t *etimeidx,
			    igraph_integer_t pno_of_events,
			    const igraph_vector_t *authors,
			    const igraph_vector_t *eventsizes,
			    igraph_integer_t pmaxpapers);
int igraph_revolver_error_p_p(const igraph_t *graph,
			      igraph_lazy_adjedgelist_t *adjlist,
			      const igraph_matrix_t *kernel,
			      const igraph_vector_t *st,
			      const igraph_vector_t *vtime,
			      const igraph_vector_t *vtimeidx,
			      const igraph_vector_t *etime,
			      const igraph_vector_t *etimeidx,
			      igraph_integer_t pno_of_events,
			      const igraph_vector_t *authors,
			      const igraph_vector_t *eventsizes,
			      igraph_integer_t pmaxpapers,
			      igraph_real_t *logprob,
			      igraph_real_t *lognull);

/* -------------------------------------------------- */
/* Maximum likelihood revolver                        */
/* -------------------------------------------------- */

int igraph_revolver_ml_d(const igraph_t *graph,
			 igraph_integer_t niter,
			 igraph_vector_t *kernel,
			 igraph_vector_t *cites,
			 igraph_real_t delta,
			 const igraph_vector_t *filter,
			 igraph_real_t *logprob,
			 igraph_real_t *logmax);

int igraph_revolver_probs_d(const igraph_t *graph,
			    const igraph_vector_t *kernel,
			    igraph_vector_t *logprobs,
			    igraph_vector_t *logcited,
			    igraph_vector_t *logciting,
			    igraph_bool_t ntk);

int igraph_revolver_ml_de(const igraph_t *graph,
			  igraph_integer_t niter,
			  igraph_matrix_t *kernel,
			  const igraph_vector_t *cats,
			  igraph_matrix_t *cites,
			  igraph_real_t delta,
			  const igraph_vector_t *filter,
			  igraph_real_t *logprob,
			  igraph_real_t *logmax);

int igraph_revolver_probs_de(const igraph_t *graph,
			     const igraph_matrix_t *kernel,
			     const igraph_vector_t *cats,
			     igraph_vector_t *logprobs,
			     igraph_vector_t *logcited,
			     igraph_vector_t *logciting);

int igraph_revolver_ml_ade(const igraph_t *graph,
			   igraph_integer_t niter,
			   igraph_array3_t *kernel,
			   const igraph_vector_t *cats,
			   igraph_array3_t *cites,
			   igraph_integer_t pagebins,
			   igraph_real_t delta,
			   const igraph_vector_t *filter,
			   igraph_real_t *logprob,
			   igraph_real_t *logmax);

int igraph_revolver_probs_ade(const igraph_t *graph,
			      const igraph_array3_t *kernel,
			      const igraph_vector_t *cats,
			      igraph_vector_t *logprobs,
			      igraph_vector_t *logcited,
			      igraph_vector_t *logciting);

int igraph_revolver_ml_f(const igraph_t *graph,
			 igraph_integer_t niter,
			 igraph_vector_t *kernel,
			 igraph_vector_t *cites,
			 igraph_real_t delta,
			 igraph_real_t *logprob,
			 igraph_real_t *logmax);

int igraph_revolver_ml_df(const igraph_t *graph,
			  igraph_integer_t niter,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *cites,
			  igraph_real_t delta,
			  igraph_real_t *logprob,
			  igraph_real_t *logmax);

int igraph_revolver_ml_l(const igraph_t *graph,
			 igraph_integer_t niter,
			 igraph_vector_t *kernel,
			 igraph_vector_t *cites,
			 igraph_integer_t pagebins,
			 igraph_real_t delta,
			 igraph_real_t *logprob,
			 igraph_real_t *logmax);

int igraph_revolver_ml_ad(const igraph_t *graph,
			  igraph_integer_t niter,
			  igraph_matrix_t *kernel,
			  igraph_matrix_t *cites,
			  igraph_integer_t pagebins,
			  igraph_real_t delta,
			  const igraph_vector_t *filter,
			  igraph_real_t *logprob,
			  igraph_real_t *logmax);

int igraph_revolver_probs_ad(const igraph_t *graph,
			     const igraph_matrix_t *kernel,
			     igraph_vector_t *logprobs,
			     igraph_vector_t *logcited,
			     igraph_vector_t *logciting,
			     igraph_bool_t ntk);

int igraph_revolver_ml_D(const igraph_t *graph,
			 igraph_vector_t *res,
			 igraph_real_t *Fmin,			 
			 igraph_real_t abstol, igraph_real_t reltol, int maxit,
			 igraph_scalar_function_t *A_fun,
			 igraph_vector_function_t *dA_fun,
			 const igraph_vector_t *filter,
			 igraph_integer_t *fncount, igraph_integer_t *grcount);

int igraph_revolver_ml_D_alpha(const igraph_t *graph,
			       igraph_real_t *alpha, igraph_real_t *Fmin,
			       igraph_real_t abstol, igraph_real_t reltol, 
			       int maxit, const igraph_vector_t *filter,
			       igraph_integer_t *fncount, 
			       igraph_integer_t *grcount);

int igraph_revolver_ml_D_alpha_a(const igraph_t *graph,
				 igraph_real_t *alpha, igraph_real_t *a,
				 igraph_real_t *Fmin,
				 igraph_real_t abstol, igraph_real_t reltol,
				 int maxit, const igraph_vector_t *filter,
				 igraph_integer_t *fncount, 
				 igraph_integer_t *grcount);

int igraph_revolver_ml_DE(const igraph_t *graph,
			  const igraph_vector_t *cats,
			  igraph_vector_t *res,
			  igraph_real_t *Fmin,
			  igraph_real_t abstol, igraph_real_t reltol, int maxit,
			  igraph_scalar_function_t *A_fun,
			  igraph_vector_function_t *dA_fun,
			  const igraph_vector_t *filter,
			  igraph_integer_t *fncount, 
			  igraph_integer_t *grcount,
			  igraph_vector_t *lastderiv);

int igraph_revolver_ml_DE_alpha_a(const igraph_t *graph,
				  const igraph_vector_t *cats,
				  igraph_real_t *alpha, igraph_real_t *a,
				  igraph_vector_t *coeffs,
				  igraph_real_t *Fmin,
				  igraph_real_t abstol, igraph_real_t reltol,
				  int maxit, const igraph_vector_t *filter,
				  igraph_integer_t *fncount,
				  igraph_integer_t *grcount);

int igraph_revolver_ml_AD(const igraph_t *graph,
			  igraph_vector_t *res,
			  igraph_real_t *Fmin,
			  igraph_real_t abstol, igraph_real_t reltol, int maxit,
			  igraph_scalar_function_t *A_fun,
			  igraph_vector_function_t *dA_fun,
			  int agebins, const igraph_vector_t *filter,
			  igraph_integer_t *fncount, 
			  igraph_integer_t *grcount,
			  igraph_vector_t *lastderiv);

int igraph_revolver_ml_AD_alpha_a_beta(const igraph_t *graph,
				       igraph_real_t *alpha, igraph_real_t *a,
				       igraph_real_t *beta, igraph_real_t *Fmin,
				       igraph_real_t abstol, igraph_real_t reltol,
				       int maxit, int agebins, 
				       const igraph_vector_t *filter,
				       igraph_integer_t *fncount,
				       igraph_integer_t *grcount);

int igraph_revolver_ml_AD_dpareto(const igraph_t *graph,
				  igraph_real_t *alpha, igraph_real_t *a,
				  igraph_real_t *paralpha, igraph_real_t *parbeta,
				  igraph_real_t *parscale,
				  igraph_real_t *Fmin,
				  igraph_real_t abstol, igraph_real_t reltol,
				  int maxit, int agebins, 
				  const igraph_vector_t *filter,
				  igraph_integer_t *fncount,
				  igraph_integer_t *grcount);

int igraph_revolver_ml_AD_dpareto_eval(const igraph_t *graph,
				       igraph_real_t alpha, igraph_real_t a,
				       igraph_real_t paralpha, 
				       igraph_real_t parbeta,
				       igraph_real_t parscale,
				       igraph_real_t *value,
				       igraph_vector_t *deriv,
				       int agebins,
				       const igraph_vector_t *filter);



int igraph_revolver_ml_ADE(const igraph_t *graph,
			   const igraph_vector_t *cats,
			   igraph_vector_t *res,
			   igraph_real_t *Fmin,
			   igraph_real_t abstol, igraph_real_t reltol, int maxit,
			   igraph_scalar_function_t *A_fun,
			   igraph_vector_function_t *dA_fun,
			   int agebins, const igraph_vector_t *filter,
			   igraph_integer_t *fncount, 
			   igraph_integer_t *grcount,
			   igraph_vector_t *lastderiv);

int igraph_revolver_probs_ADE(const igraph_t *graph,
			      igraph_scalar_function_t *A_fun,
			      const igraph_matrix_t *par,
			      const igraph_vector_t *cats,
			      const igraph_vector_t *gcats,
			      int agebins,
			      igraph_vector_t *logprobs,
			      igraph_vector_t *logcited,
			      igraph_vector_t *logciting);

int igraph_revolver_ml_ADE_alpha_a_beta(const igraph_t *graph,
					const igraph_vector_t *cats,
					igraph_real_t *alpha, igraph_real_t *a,
					igraph_real_t *beta, igraph_vector_t *coeffs,
					igraph_real_t *Fmin,
					igraph_real_t abstol, igraph_real_t reltol,
					int maxit, int agebins, 
					const igraph_vector_t *filter,
					igraph_integer_t *fncount,
					igraph_integer_t *grcount);

int igraph_revolver_ml_ADE_dpareto(const igraph_t *graph,
				   const igraph_vector_t *cats,
				   igraph_real_t *alpha, igraph_real_t *a,
				   igraph_real_t *paralpha, igraph_real_t *parbeta,
				   igraph_real_t *parscale, igraph_vector_t *coeffs,
				   igraph_real_t *Fmin,
				   igraph_real_t abstol, igraph_real_t reltol,
				   int maxit, int agebins, 
				   const igraph_vector_t *filter,
				   igraph_integer_t *fncount,
				   igraph_integer_t *grcount);

int igraph_revolver_ml_ADE_dpareto_eval(const igraph_t *graph,
					const igraph_vector_t *cats,
					igraph_real_t alpha, igraph_real_t a,
					igraph_real_t paralpha, 
					igraph_real_t parbeta,
					igraph_real_t parscale,
					const igraph_vector_t *coeffs,
					igraph_real_t *value,
					igraph_vector_t *deriv,
					int agebins,
					const igraph_vector_t *filter);

int igraph_revolver_ml_ADE_dpareto_evalf(const igraph_t *graph,
					 const igraph_vector_t *cats,
					 const igraph_matrix_t *par,
					 igraph_vector_t *value,
					 int agebins, 
					 const igraph_vector_t *filter);

int igraph_revolver_probs_ADE_dpareto(const igraph_t *graph,
				      const igraph_matrix_t *par,
				      const igraph_vector_t *cats,
				      const igraph_vector_t *gcats,
				      int agebins,
				      igraph_vector_t *logprobs,
				      igraph_vector_t *logcited,
				      igraph_vector_t *logciting);

__END_DECLS

#endif
