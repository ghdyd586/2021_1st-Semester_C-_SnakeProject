
void make_gate(int selmap, vector<snakebody>& gate){
    srand((unsigned) time(0));

    int in_gate_row=0, in_gate_col=0, out_gate_row=0, out_gate_col=0;
    in_gate_row=rand()%30;
    in_gate_col=rand()%30;
    out_gate_row=rand()%30;
    out_gate_row=rand()%30;
    while(TRUE){
      if(map[selmap][in_gate_row][in_gate_col] ==1) break;
      in_gate_row=rand()%30;
      in_gate_col=rand()%30;
    }
    map[selmap][in_gate_row][in_gate_col]=7;

    while(TRUE){
      if(map[selmap][out_gate_row][out_gate_col] ==1) break;
      out_gate_row=rand()%30;
      out_gate_col=rand()%30;

    }
    map[selmap][out_gate_row][out_gate_col]=7;
    gate.push_back(snakebody(in_gate_row,in_gate_col));
    gate.push_back(snakebody(out_gate_row,out_gate_col));
}
