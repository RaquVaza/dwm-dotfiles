extern const unsigned int gappx;
extern const unsigned int gappi;

void
fibonacci(Monitor *mon, int s) {
	unsigned int i, n;
	int nx, ny, nw, nh;
	Client *c;

	for(n = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next), n++);
	if(n == 0)
		return;

	/* Начальная область с outer gaps */
	nx = mon->wx + gappx;
	ny = mon->wy + gappx;
	nw = mon->ww - 2 * gappx;
	nh = mon->wh - 2 * gappx;

	for(i = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next)) {
		if((i % 2 && nh / 2 > 2 * c->bw)
		   || (!(i % 2) && nw / 2 > 2 * c->bw)) {
			if(i < n - 1) {
				/* Делим область пополам с учётом inner gap */
				if(i % 2)
					nh = (nh - gappi) / 2;
				else
					nw = (nw - gappi) / 2;
				if((i % 4) == 2 && !s)
					nx += nw + gappi;
				else if((i % 4) == 3 && !s)
					ny += nh + gappi;
			}
			if((i % 4) == 0) {
				if(s)
					ny += nh + gappi;
				else
					ny -= nh + gappi;
			} else if((i % 4) == 1)
				nx += nw + gappi;
			else if((i % 4) == 2)
				ny += nh + gappi;
			else if((i % 4) == 3) {
				if(s)
					nx += nw + gappi;
				else
					nx -= nw + gappi;
			}
			if(i == 0) {
				if(n != 1)
					nw = (mon->ww - 2 * gappx) * mon->mfact;
				ny = mon->wy + gappx;
			} else if(i == 1)
				nw = mon->ww - 2 * gappx - nw - gappi;
			i++;
		}
		resize(c, nx, ny, nw - 2 * c->bw, nh - 2 * c->bw, False);
	}
}

void
dwindle(Monitor *mon) {
	fibonacci(mon, 1);
}

void
spiral(Monitor *mon) {
	fibonacci(mon, 0);
}
