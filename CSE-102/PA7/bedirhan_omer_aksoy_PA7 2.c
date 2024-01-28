#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

enum type_of_gate {INPUT, OUTPUT, AND, OR, NOT, FLIPFLOP};

// it is the structure of every single gates
struct gate {
    enum type_of_gate type; // it is the type of the gates
    char name[MAX_NAME_LENGTH]; // it is the name of the gates
    int num_inputs; // number of input gates
    struct gate** inputs; // array of pointers to input gates
    struct gate* output; // pointer to output gates
    int output_value; // output value of the gates
};
// it is the struct of the whole circuit
struct circuit {
  int num_gates; // number of the gates in the circuit
  struct gate** gates; // array of pointers to the gates
};

// it creates circuit according to circuit.txt
void create_circuit(struct circuit* circuit) {
    size_t size;
    // it opens the file in reading mode
    FILE* fp1 = fopen("circuit.txt", "r");
    
      // initialize the gate
    circuit->num_gates = 0;
     // it allocates the memory for the gate struct
    circuit->gates = malloc(sizeof(struct gate*));

   
    char line[30];
     // it reads all the line in circuit.txt
    while (fgets(line, sizeof(line), fp1) != NULL) {
        line[strcspn(line, "\n")] = 0;
            // it parse the line according to space characters
        char* token = strtok(line, " ");
        
        //if (token == NULL) continue; // Skip empty lines

            // it checks the keyword of the line 
        if (strcmp(token, "GATE") == 0) {   
            // if it is gate, it creates new gate and find its type
            token = strtok(NULL, " ");
            
           
            // it determines the type of the gate
            enum type_of_gate type;
            if (strcmp(token, "INPUT") == 0) type = INPUT;

            else if (strcmp(token, "OUTPUT") == 0) type = OUTPUT;

            else if (strcmp(token, "AND") == 0) type = AND; 

            else if (strcmp(token, "OR") == 0) type = OR;
            
            else if (strcmp(token, "NOT") == 0) type = NOT;
            
            else if (strcmp(token, "FLIPFLOP") == 0) type = FLIPFLOP;
            
            
            //it takes the name of the gate
            token = strtok(NULL, " ");           
            char* name = token;
            // it creates a new gate and adds it to the circuit
            struct gate* new_gate = malloc(sizeof(struct gate));
            // determine the type the type
            new_gate->type = type;
            //determine the name
            strncpy(new_gate->name, name, MAX_NAME_LENGTH);
            //it set the number of inputs to zero
            new_gate->num_inputs = 0;
            // set the inputs to null
            new_gate->inputs = NULL;
            // set the output to null
            new_gate->output = NULL;
            //set the output value to zero
            new_gate->output_value = 0;
            // add the new gate to circuit
            circuit->gates[circuit->num_gates++] = new_gate;
            // it reallocates the memory after the new gate added
            circuit->gates = realloc(circuit->gates, (circuit->num_gates + 1) * sizeof(struct gate*));
                  
        }
        //if it is connection it takes from_gate and to_gate
        else if (strcmp(token, "CONNECTION") == 0) {

            // it takes from_gate_name 
            token = strtok(NULL, " ");
            char* from_gate_name = token;

            //it takes to_gate_name
            token = strtok(NULL, " ");
            char* to_gate_name = token;

            // initialize them to null 
            struct gate* from_gate = NULL;
            struct gate* to_gate = NULL;
            
            for (int i = 0; i < circuit->num_gates; i++) {
                // it searchs for the from_gate_name from the circuit
                if (strcmp(circuit->gates[i]->name, from_gate_name) == 0) {
                    from_gate = circuit->gates[i];
                }

                // it searchs for the to_gate_name from the circuit
                if (strcmp(circuit->gates[i]->name, to_gate_name) == 0) {
                    to_gate = circuit->gates[i];
                }
            }
           
             
            to_gate->num_inputs++;
            // it reallocates the memory after adding new gate to the circuit
            to_gate->inputs = realloc(to_gate->inputs, to_gate->num_inputs * sizeof(struct gate*));
           // it connects the from_gate to to_gate's output
            to_gate->inputs[to_gate->num_inputs - 1] = from_gate;
            from_gate->output = to_gate;
        }
    }
    fclose(fp1);
}

// it calculates the output of a single gate
void calculate_gate(struct gate* gate) {
    // input gates will be filled in the main function
    // output gates output is directly the input struct's output
    if(gate->type == OUTPUT) gate->output_value = gate->inputs[0]->output_value;

    // AND gate's output is 1 if all inputs are 1, otherwise it is 0
    else if(gate->type == AND){
        gate->output_value = 1;
        for (int i = 0; i < gate->num_inputs; i++) {
        gate->output_value = gate->output_value & gate->inputs[i]->output_value;
        }
    }
    // OR gate's output is 0 if both inputs is 0, otherwise it is 1
    else if(gate->type == OR){
        gate->output_value = 0;
        for (int i = 0; i < gate->num_inputs; i++) {
        gate->output_value = gate->output_value | gate->inputs[i]->output_value;
        }
    }
    // NOT gate's output is the opposite of the input gate's output value
    else if(gate->type == NOT) gate->output_value = !gate->inputs[0]->output_value;
    
    // FLIPFLOP gate's output is initially 1, if input is 1, it becomes its opposite number
    else if(gate->type == FLIPFLOP){
        if (gate->inputs[0]->output_value == 1) {
            gate->output_value = !gate->output_value;
        }
    }
}
// it calculates the output of the circuit with input values
void calculate_circuit(struct circuit* circuit, int* inputs, int* outputs,int lenght_of_inputs,int number_of_inputs) {
    
    // it sends input values to input gates
    for (int i = 0; i < circuit->num_gates; i++) {
        if (circuit->gates[i]->type == INPUT) {
          circuit->gates[i]->output_value = inputs[i];
        }
    }

    // it calculates the output of every single gate
    for (int i = 0; i <circuit->num_gates; i++) {
        calculate_gate(circuit->gates[i]);
    }

    // it assigns the output values of every single gate
    int output_index = 0;
    for (int i = 0; i < circuit->num_gates; i++) {
        if (circuit->gates[i]->type == OUTPUT) {
        //it prints the output value
        printf("%d",circuit->gates[i]->output_value);
        }
    }
}

int main() {
    
    struct circuit circuit;                     // struct for circuit 
    create_circuit(&circuit);                    // it creates circuit according to circuit.txt file
    size_t lenght_of_inputs;                    // number of input gates
    int number_of_inputs = 0;                   // number of inputs
    int input_values[circuit.num_gates];        // input values for input gates
    int output_values[circuit.num_gates];       // output values

    // it opens the input.txt in reading mode
    FILE* fp = fopen("input.txt", "r");
   
    char line[10];                                      // it saves the input data 
    while (fgets(line, sizeof(line), fp) != NULL) {     // it reads the lines until EOF

        if(line[0]=='\n') continue;                     // if the firse character is '\n' it means the line is empty so it continue to searching new lines

        number_of_inputs++;                             // number of inputs increases in every turn
        line[strcspn(line, "\n")] = 0;                  // it removes the \n character end of the lines 
        
        for (int i = 0; i < sizeof(line-1); i++) {      // it turns input strings into an integer array

            if (line[i] == '1') {                       // if it is 1, it assigns the input values [i]'th element to 1 
                input_values[i] = 1;
            } 
            
            else if (line[i] == '0') {                  // if it is 0, it assigns the input values [i]'th element to 0
                input_values[i] = 0;
            } 
        }
        
        lenght_of_inputs =  sizeof(line-1);             // size of line - 1 (because of the \n character) equals to lenght of line 

        //it calculates and prints the output of the circuit
        calculate_circuit(&circuit, input_values, output_values,lenght_of_inputs,number_of_inputs);
        printf("\n");
    }
    // it close the input file
    fclose(fp);

    // it free the memory allocated by gates inputs and outputs
    for (int i = 0; i < circuit.num_gates; i++) {       // first i free the inputs and output pointers into the gates 
        free(circuit.gates[i]->inputs);
        
        free(circuit.gates[i]->output);
    } 
    free(circuit.gates);                                // then i free the all gate pointers 

return 0;
}