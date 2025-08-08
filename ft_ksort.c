/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:42:29 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/06 12:49:49 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <math.h>
#include <limits.h>

typedef struct {
    int size;
    t_list *top;
} t_stack;

typedef struct {
    int start;
    int end;
} t_group;

// 计算平方根（向上取整）
int ft_sqrt_ceil(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n < n) ? sqrt_n + 1 : sqrt_n;
}

// 寻找最小值节点
t_list *find_min_node(t_stack *s) {
    t_list *min_node = s->top;
    t_list *current = s->top->next;

    while (current) {
        if (current->index < min_node->index) {
            min_node = current;
        }
        current = current->next;
    }
    return min_node;
}

// 将特定节点旋转到栈顶
void rotate_node_to_top(t_stack *s, t_list *target) {
    int pos = 0;
    t_list *current = s->top;

    // 计算目标位置
    while (current && current != target) {
        pos++;
        current = current->next;
    }

    // 执行旋转
    if (pos <= s->size / 2) {
        for (int i = 0; i < pos; i++) {
            ra(s);
        }
    } else {
        for (int i = 0; i < s->size - pos; i++) {
            rra(s);
        }
    }
}

// 分组推入 B 栈
void push_groups_to_b(t_stack *a, t_stack *b, int k) {
    const int n = a->size;
    const int group_size = (n + k - 1) / k; // 向上取整

    // 创建组边界数组
    t_group groups[k];
    for (int i = 0; i < k; i++) {
        groups[i].start = i * group_size;
        groups[i].end = (i + 1) * group_size - 1;
        if (groups[i].end >= n) groups[i].end = n - 1;
    }

    // 按特定顺序推入组（从高索引组到低索引组）
    for (int group_index = k - 1; group_index >= 0; group_index--) {
        int count = 0;
        int group_count = groups[group_index].end - groups[group_index].start + 1;

        while (count < group_count) {
            if (a->top->index >= groups[group_index].start &&
                a->top->index <= groups[group_index].end) {

                pb(a, b);
                count++;

                // 保持组内相对有序（小值在栈顶）
                if (b->size > 1 && b->top->index > b->top->next->index) {
                    sb(b);
                }
            } else {
                ra(a);
            }
        }
    }
}

// 组内排序（使用插入排序）
void sort_group_in_b(t_stack *a, t_stack *b, int group_size) {
    // 临时移回 A 栈进行排序
    for (int i = 0; i < group_size; i++) {
        pa(a, b);
    }

    // 对组内元素进行插入排序
    for (int i = 1; i < group_size; i++) {
        t_list *key = a->top;
        for (int j = 0; j < i; j++) ra(a);

        int j = i - 1;
        while (j >= 0 && a->top->index > key->index) {
            rra(a);
            j--;
        }
        sa(a);
        while (j >= 0) {
            ra(a);
            j--;
        }
    }

    // 推回 B 栈
    for (int i = 0; i < group_size; i++) {
        pb(a, b);
    }
}

// 合并阶段
void merge_groups(t_stack *a, t_stack *b) {
    while (b->size > 0) {
        // 找到 B 栈中的最小值
        t_list *min_node = find_min_node(b);
        rotate_node_to_top(b, min_node);

        // 推回 A 栈
        pa(a, b);

        // 优化：如果 A 栈顶元素大于下一个，交换
        if (a->size > 1 && a->top->index > a->top->next->index) {
            sa(a);
        }
    }
}

// 主排序函数
void k_sort(t_stack *a, t_stack *b) {
    if (a->size <= 1) return;

    // 计算 k 值
    int k = ft_sqrt_ceil(a->size);
    if (k < 3) k = 3; // 最小分组数

    // 1. 分组推入 B 栈
    push_groups_to_b(a, b, k);

    // 2. 组内排序
    int group_size = (a->size + k - 1) / k;
    for (int i = 0; i < k; i++) {
        int current_size = (b->size < group_size) ? b->size : group_size;
        sort_group_in_b(a, b, current_size);
    }

    // 3. 合并阶段
    merge_groups(a, b);

    // 最终调整：将最小值旋转到栈顶
    t_list *min_node = find_min_node(a);
    rotate_node_to_top(a, min_node);
}
