MODULE_big = pgqr
OBJS = pgqr.o QR_Encode.o
EXTENSION = pgqr
DATA = pgqr--1.0.sql

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)

include $(PGXS)

