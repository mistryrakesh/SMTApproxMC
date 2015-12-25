# README #
`approxMC.py` - script for approximate model counting.

### Running The Script ###
The script may be run as:  
    ```
    python3 approxMC.py <input_SMT2_file> <primes_file> <num_iterations> <log_file> <output_file>
    ```

### SMT2 File Format ###
Currently the SMT2 parser is very limited and only supports QF\_BV SMT2 file of the following format:

    declaration and other non-assert statements  
    assert-statements  
    "(check-sat)" statement

### Prerequisites ###
The script requires the following to run:

  1. Python 3
  2. doalarm - [https://directory.fsf.org/wiki/Doalarm](https://directory.fsf.org/wiki/Doalarm)
