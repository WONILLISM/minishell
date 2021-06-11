#include "../includes/minish.h"

void	init_redir(t_data *data)
{
	data->rd = (t_redir *)malloc(sizeof(t_redir));
	data->rd->sign = data->cmd->rd_flag;
	data->rd_buf[data->rd_buf_idx + 1] = 0;
	data->rd->file_name = ft_strdup(data->rd_buf);
	free(data->rd_buf);
	ft_lstadd_back(&data->cmd->rd_lst, ft_lstnew(data->rd));

	data->cmd->rd_flag = 0;
	data->rd_buf = ft_calloc(data->buf_size, sizeof(char));
	data->rd_buf_idx = 0;
	data->input_idx--;
}

void	chk_redir_sign(char *input, t_data *data)
{
	if (input[data->input_idx] == '>')
	{
		if (data->cmd->rd_flag == 0 || (data->cmd->rd_flag == 1 && !*data->rd_buf))
			data->cmd->rd_flag++;
		else if ((data->cmd->rd_flag == 2 || data->cmd->rd_flag == 1) && *data->rd_buf)
			init_redir(data);
		else
			printf("ERROR\n");
	}
	else if (input[data->input_idx] == '<')
	{
		if (data->cmd->rd_flag == 0)
			data->cmd->rd_flag--;
		else if (data->cmd->rd_flag == -1 && *data->rd_buf)
			init_redir(data);
		else
			printf("ERROR\n");
	}
	else
		printf("error\n");
}

void	chk_redir_filename(char *input, t_data *data)
{
	if (*data->rd_buf && data->cmd->quote == 0 && input[data->input_idx] == ' ')
		init_redir(data);
	else
	{
		data->rd_buf[data->rd_buf_idx++] = input[data->input_idx];
	}
}