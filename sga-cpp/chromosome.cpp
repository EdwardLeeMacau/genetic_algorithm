/***************************************************************************
 *   Copyright (C) 2004 by Tian-Li Yu                                      *
 *   tianliyu@cc.ee.ntu.edu.tw                                             *
 ***************************************************************************/

#include <stdio.h>
#include "global.h"
#include "chromosome.h"

/**
 * Create an empty gene container.
 * @brief Default constructor
 * @see Chromosome::Chromosome(int n_length)
 */
Chromosome::Chromosome()
{
    length = 0;
    gene = NULL;
    evaluated = false;
}

/**
 * Create a chromosome with specified length
 * @brief Constructor
 * @param[in] n_length The length of chromosome
 * @see Chromosome::Chromosome()
 */
Chromosome::Chromosome (int n_length)
{
    gene = NULL;
    init (n_length);
}


Chromosome::~Chromosome ()
{
    delete[] gene;
}

/**
 * Reset chromosome with specified length
 * @param[in] n_length    length of chromosome
 */
void Chromosome::init (int n_length)
{
    length = n_length;

    if (gene != NULL)
        delete[] gene;

    gene = new bool[length];
    evaluated = false;
}

/**
 * Get the value of gene in specified index.
 * @param[in] index    Index of the bit to be queried.
 */
int Chromosome::getVal (int index) const
{
    if (index < 0 || index > length)
        outputErrMsg ("Index overrange in Chromosome::operator[]");

    return (gene[index])? 1:0;
}

/**
 * Set the value of gene in specified index.
 * @param[in] index    Index of the bit to be configured.
 * @param[in] val      Target value
 */
void Chromosome::setVal (int index, int val)
{
    if (index < 0 || index > length)
        outputErrMsg ("Index overrange in Chromosome::operator[]");

    gene[index] = (val==1)? true:false;
    evaluated = false;
}

/**
 * Return fitness of the chromosome
 * @details Calculates fitness if it's not calculated before.
 * @return Fitness value
 * @see Chromosome::evaluate()
 */
double Chromosome::getFitness ()
{
    if (evaluated)
        return fitness;
    else
        return (fitness = evaluate ());
}

/**
 * Evaluate fitness of the chromosome
 * @return Fitness value
 * @see Chromosome::getFitness
 */
double Chromosome::evaluate ()
{
    evaluated = true;
    return oneMax ();
}

/**
 * Evaluate fitness of gene with one-max function
 * @return double
 */
double Chromosome::oneMax () const
{
    double result = 0;

    for (int i = 0; i < length; i++)
        result += gene[i];

    return result;
}

/**
 * For OneMax
 * @brief Get max fitness of one-max function, which indicates searching is ended.
 */
double Chromosome::getMaxFitness () const
{
    return ((double)length - 1e-6);
}

/**
 * @brief Assign operator
 * @param[in] c    Reference of chromosome
 */
Chromosome& Chromosome::operator= (const Chromosome & c)
{
    int i;

    if (length != c.length) {
        length = c.length;
        delete[] gene;
        init (length);
    }

    evaluated = c.evaluated;
    fitness = c.fitness;

    for (i = 0; i < length; i++)
        gene[i] = c.gene[i];

    return *this;
}


void Chromosome::printf () const
{
    for (int i = 0; i < length; i++)
        ::printf ("%d", gene[i]);
}

/**
 * @return whether the chromosome is evaluated.
 */
bool Chromosome::isEvaluated () const
{
    return evaluated;
}

/**
 * @return The length of chromosome
 */
int Chromosome::getLength () const
{
    return length;
}

