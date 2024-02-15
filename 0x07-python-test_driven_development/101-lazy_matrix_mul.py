#!/usr/bin/python3
"""Defines a matrix multiplication function using numpy."""
import numpy as np


def lazy_matrix_mul(m_a, m_b):
    """Multiply two matrices.

    Args:
        m_a (list of lists of ints/floats): The first matrix.
        m_b (list of lists of ints/floats): The second matrix.

    Returns:
        A new matrix representing the multiplication of m_a by m_b.
    """

    return (np.matmul(m_a, m_b))
