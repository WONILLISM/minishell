#include "../includes/minish.h"

void chk_space_flag(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == -1)
				strs[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int chk_var_name(t_data *data, char *input)
{
	int ret;
	char c;

	ret = 0;
	c = *(input + data->input_idx);
	if (ret == 0 && ft_isdigit(c))
	{
		return (1);
	}
	while (c == '_' || ft_isalnum(c))
	{
		ret++;
		c = *(input + data->input_idx + ret);
	}
	return (ret);
}

int lst_add_cmd(t_data *data, t_list *cmd_root, int flag)
{
	char *tmp;

	tmp = ft_strltrim(data->buf, " ");
	free(data->buf);
	data->buf = tmp;
	data->cmd->argv = ft_split(data->buf, ' ');
	chk_space_flag(data->cmd->argv);
	data->cmd->flag = flag;
	if (!(data->cmd->argv)[0] && flag >= 0)
		return (ERROR);
	else
	{
		ft_lstadd_back(&cmd_root, ft_lstnew(data->cmd));
		if (data->cmd->quote)
			return (ERROR);
		data->cmd = ft_calloc(1, sizeof(t_cmd));
		data->last_node = ft_lstlast(cmd_root);
		data->last_node->next = 0;
	}
	data->buf_idx = 0;
	free(data->buf);
	data->buf = ft_calloc(data->buf_size, sizeof(char));
	return (SUCCESS);
}