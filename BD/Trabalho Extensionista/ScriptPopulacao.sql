-- Script para popular o banco de dados

-- Inserindo dados na tabela Classe
INSERT INTO Classe (ID_Classe, Nome, Descricao) VALUES
(1, 'Combatente', 'Especializado em combate corpo a corpo e uso de armas.'),
(2, 'Especialista', 'Habilidades únicas e específicas para diferentes situações.'),
(3, 'Ocultista', 'Conhecimentos profundos sobre o ocultismo e rituais.'),
(4, 'Sobrevivente', 'Habilidades de sobrevivência e resistência.');

-- Inserindo dados na tabela Origem
INSERT INTO Origem (ID_Origem, Nome, Descricao) VALUES
(1, 'Acadêmico', 'Profissional dedicado ao estudo e ensino.'),
(2, 'Agente de Saúde', 'Especialista em cuidados médicos e saúde.'),
(3, 'Artista', 'Criador de obras de arte e performances.'),
(4, 'Atleta', 'Profissional do esporte e atividades físicas.'),
(5, 'Chef', 'Cozinheiro profissional, especializado em gastronomia.'),
(6, 'Criminoso', 'Envolvido em atividades ilegais e furtivas.'),
(7, 'Cultista Arrependido', 'Antigo cultista que agora busca redenção.'),
(8, 'Desgarrado', 'Indivíduo que vive à margem da sociedade.'),
(9, 'Engenheiro', 'Profissional técnico especializado em engenharia.'),
(10, 'Executivo', 'Líder empresarial, especializado em gestão.'),
(11, 'Investigador', 'Profissional dedicado à investigação e pesquisa.'),
(12, 'Lutador', 'Especialista em combate corpo a corpo.'),
(13, 'Magnata', 'Pessoa rica e influente, apoiador da Ordem.'),
(14, 'Mercenário', 'Soldado contratado para missões específicas.'),
(15, 'Militar', 'Profissional das forças armadas, especializado em tática.'),
(16, 'Operário', 'Trabalhador manual, especializado em construção.'),
(17, 'Policial', 'Agente da lei, especializado em segurança pública.'),
(18, 'Religioso', 'Líder espiritual, especializado em rituais religiosos.'),
(19, 'Servidor Público', 'Funcionário do governo, dedicado ao serviço público.'),
(20, 'Teórico da Conspiração', 'Investigador de teorias conspiratórias.'),
(21, 'T.I.', 'Profissional de tecnologia da informação.'),
(22, 'Trabalhador Rural', 'Especialista em agricultura e vida rural.');

-- Inserindo dados na tabela Jogador
INSERT INTO Jogador (ID_Jogador, Nome, Gênero) VALUES
(1, 'João', 'M'),
(2, 'Maria', 'F'),
(3, 'Carlos', 'M'),
(4, 'Ana', 'F');

-- Inserindo dados na tabela Personagem
INSERT INTO Personagem (ID_Personagem, Nome, Gênero, `Pontos de Vida`, `Pontos de Sanidade`, `Pontos de Esforço`, NEX, Jogador_ID_Jogador, Classe_ID_Classe, Origem_ID_Origem) VALUES
(1, 'Arthus', 'M', 100, 80, 50, 10, 1, 1, 1),
(2, 'Luna', 'F', 90, 85, 60, 15, 2, 2, 2),
(3, 'Maximus', 'M', 120, 70, 40, 20, 3, 3, 3),
(4, 'Selene', 'F', 80, 90, 55, 25, 4, 4, 4);

-- Inserindo dados na tabela Trilha
INSERT INTO Trilha (ID_Trilha, Nome, Descricao, Classe_ID_Classe) VALUES
(1, 'Caçador de Monstros', 'Especialista em rastrear e combater criaturas sobrenaturais.', 1),
(2, 'Médico de Campo', 'Oferece suporte médico em situações de combate.', 2),
(3, 'Invocador', 'Especializado em rituais de invocação.', 3),
(4, 'Sobrevivencialista', 'Especialista em técnicas de sobrevivência extrema.', 4);

-- Inserindo dados na tabela Habilidade
INSERT INTO Habilidade (ID_Habilidade, Nome, Descricao, Trilha_ID_Trilha, Origem_ID_Origem) VALUES
(1, 'Saber é Poder', 'Utiliza seu vasto conhecimento para obter vantagens.', 1, 1),
(2, 'Técnica Medicinal', 'Habilidade avançada em procedimentos médicos.', 2, 2),
(3, 'Magnum Opus', 'Criação de obras de arte com efeitos especiais.', 3, 3),
(4, '110%', 'Desempenho físico máximo em competições.', 4, 4);

-- Inserindo dados na tabela Perícia
INSERT INTO Perícia (ID_Pericia, Nome, Descricao, Origem_ID_Origem) VALUES
(1, 'Ciências', 'Estudo avançado de ciências naturais e sociais.', 1),
(2, 'Investigação', 'Habilidade de conduzir investigações detalhadas.', 1),
(3, 'Intuição', 'Capacidade de perceber e interpretar sinais.', 2),
(4, 'Medicina', 'Conhecimento em práticas médicas e saúde.', 2),
(5, 'Artes', 'Habilidade em diversas formas de expressão artística.', 3),
(6, 'Enganação', 'Capacidade de enganar e ludibriar.', 3),
(7, 'Acrobacia', 'Habilidade em movimentos acrobáticos.', 4),
(8, 'Atletismo', 'Desempenho físico em atividades esportivas.', 4);

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
