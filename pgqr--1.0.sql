-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION qr" to load this file. \quit

CREATE OR REPLACE FUNCTION public.pgqr(
	IN t text,
	IN correction_level integer,
	IN model_number integer,
	IN scale integer
)
RETURNS bytea
AS 'MODULE_PATHNAME' LANGUAGE C STABLE;
