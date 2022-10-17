init_state(State& state) {
  state._nr_pr = 0;
	state._nr_qs = 0;
  state._a_t = 0;
#ifndef NOFAIR
	memset(&state._cnt, 0, sizeof(state._cnt));
#endif
#ifndef NOVSZ
  state._vsz = 0;
#endif
#ifdef HAS_LAST
	state._last = 0;
#endif
#if defined(BITSTATE) && defined(BCS) && defined(STORE_CTX)
	state._ctx = 0;
#endif
#if defined(BFS_PAR) && defined(L_BOUND)
	state._l_bnd = 0;
  state._l_sds = 0;
#endif
#ifdef EVENT_TRACE
  state_event = 0;
#endif
#ifdef TRIX
	memset(&state._ids_, 0, sizeof(state._ids_));
#else
	memset(&state.sv, 0, sizeof(state.sv));
#endif
}
void
