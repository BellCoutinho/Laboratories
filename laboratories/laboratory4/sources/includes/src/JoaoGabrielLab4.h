/**
 * @file JoaoGabrielLab4.h
 * @brief Protótipos de funções e macros para o laboratório 4.
 * @author João Gabriel Silva Coutinho (Bell Coutinho)
 * @bug Nenhum bug conhecido.
 */
#ifndef JOAOGABRIELLAB4_H_
#define JOAOGABRIELLAB4_H_


#define NUMBER_COLUMNS 2
#define NAME_SIZE 16
#define NUMBER_STUDENTS 3

/**
 * @brief Retorna a situação do aluno passado por parâmetro.
 * @param[in] name Nome no aluno a ser verificado a situação.
 * @return Retorna a situação do aluno.
 */
char *
student_status (const char name[NAME_SIZE]);

/**
 * @brief Pega da entrada padrão os nomes dos alunos.
 * @param[out] names Array3d onde os nomes dos alunos e a sua situação iram ficar.
 */
void
student_names (char names[][NUMBER_COLUMNS][NAME_SIZE]);

/**
 * @brief Mostra os nomes e a situação dos alunos.
 * @param[in] names Array3d onde os alunos e a suas situações estão armazenados.
 */
void
show (char names[][NUMBER_COLUMNS][NAME_SIZE]);

#endif /*JOAOGABRIELLAB4_H_ */
