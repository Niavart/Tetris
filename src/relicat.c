t_pieces        turn_piece_l(t_pieces piece)
{
  int           tmp;
  int           i;
  int           j;
  char          **n_mod;

  i = 0;
  tmp = piece.wid;
  piece.wid = piece.hei;
  piece.hei = tmp;
  n_mod = malloc(sizeof(char *) * (piece.hei + 1));
  while (i < piece.hei)
    {
      j = 0;
      n_mod[i] = malloc(sizeof(char) * (piece.wid + 1));
      while (j < piece.wid)
	{
	  n_mod[i][j] = piece.model[j][piece.hei - i - 1];
	  j++;
	}
      n_mod[i][j] = '\0';
      i++;
    }
  n_mod[i] = NULL;
  piece.model = n_mod;
  return (piece);
}
