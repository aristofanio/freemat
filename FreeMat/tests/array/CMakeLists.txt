ENABLE_TESTING()
ADD_TEST(wbtest_transpose_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=transpose(x1)','wbtest_transpose_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_expm_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=expm(x1)#(any(loopi==[50:51]))','wbtest_expm_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_rref_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=rref(x1)','wbtest_rref_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_rref_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#[y1,y2]=rref(x1)','wbtest_rref_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_rref_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#[y1,y2]=rref(x1,.0001)#(any(loopi==[15,62]))','wbtest_rref_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1)#(any(loopi==[50:51]))','wbtest_norm_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1,1)','wbtest_norm_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1,2)#(any(loopi==[50:51]))','wbtest_norm_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1,7)','wbtest_norm_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1,inf)','wbtest_norm_5','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_norm_6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=norm(x1,-inf)','wbtest_norm_6','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_rank_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=rank(x1)','wbtest_rank_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_rank_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=rank(x1,.0001)','wbtest_rank_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_det1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_det1')")
ADD_TEST(wbtest_det_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=det(x1)','wbtest_det_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_cond_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=cond(x1)','wbtest_cond_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_eye_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=eye(3)','wbtest_eye_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_eye_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=eye(300)','wbtest_eye_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_pinv_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=pinv(x1)','wbtest_pinv_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_isfloat1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_isfloat1')")
ADD_TEST(wbtest_nonzeros_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=nonzeros(x1)','wbtest_nonzeros_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_ndgrid_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2] = ndgrid(1:2,3:5)','wbtest_ndgrid_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_ndgrid_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3] = ndgrid(1:2,3:5,0:1)','wbtest_ndgrid_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_ndgrid_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3] = ndgrid(1:3)','wbtest_ndgrid_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_logspace_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=logspace(1,2)','wbtest_logspace_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_logspace_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=logspace(1,2,3)','wbtest_logspace_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_logspace_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=logspace(0,pi,3)','wbtest_logspace_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_squeeze_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=squeeze(x1)','wbtest_squeeze_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_flipud_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=flipud(x1)','wbtest_flipud_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_isinteger1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_isinteger1')")
ADD_TEST(wbtest_linspace_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#z=linspace(0,60000,60001);y1=z(end)','wbtest_linspace_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_linspace_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=linspace(0,1)','wbtest_linspace_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_linspace_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=linspace(1,91,91)','wbtest_linspace_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_fliplr_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=fliplr(x1)','wbtest_fliplr_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_flipdim_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=flipdim(x1,1)','wbtest_flipdim_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_flipdim_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=flipdim(x1,2)','wbtest_flipdim_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_flipdim_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=flipdim(x1,3)','wbtest_flipdim_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_meshgrid_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#[y1,y2] = meshgrid(-2:.4:2)','wbtest_meshgrid_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_meshgrid_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2] = meshgrid([1,2,3,4],[6,7,8])','wbtest_meshgrid_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_ipermute_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=ipermute(x1,[2,1])','wbtest_ipermute_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_ipermute_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=size(ipermute(permute(x1),[3,4,2,1]),[3,4,2,1])','wbtest_ipermute_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[1,0])','wbtest_circshift_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[0,-1])','wbtest_circshift_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[2,2])','wbtest_circshift_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[1,0,0])','wbtest_circshift_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[0,-1,0])','wbtest_circshift_5','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[0,0,-1])','wbtest_circshift_6','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_circshift_7 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=circshift(x1,[2,-3,1])','wbtest_circshift_7','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_shiftdim_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=shiftdim(x1,1)','wbtest_shiftdim_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_shiftdim_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=shiftdim(x1,-1)','wbtest_shiftdim_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_shiftdim_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=shiftdim(x1)','wbtest_shiftdim_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_assign1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign1')")
ADD_TEST(test_assign2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign2')")
ADD_TEST(test_assign3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign3')")
ADD_TEST(test_assign4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign4')")
ADD_TEST(test_assign5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign5')")
ADD_TEST(test_assign6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign6')")
ADD_TEST(test_assign7 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign7')")
ADD_TEST(test_assign8 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign8')")
ADD_TEST(test_assign9 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign9')")
ADD_TEST(test_assign10 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign10')")
ADD_TEST(test_assign11 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign11')")
ADD_TEST(test_assign12 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign12')")
ADD_TEST(test_assign13 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign13')")
ADD_TEST(test_assign14 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign14')")
ADD_TEST(test_assign15 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign15')")
ADD_TEST(test_assign16 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign16')")
ADD_TEST(test_assign17 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign17')")
ADD_TEST(test_assign18 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign18')")
ADD_TEST(test_assign19 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign19')")
ADD_TEST(test_assign20 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign20')")
ADD_TEST(test_assign21 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign21')")
ADD_TEST(test_assign22 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_assign22')")
ADD_TEST(test_sparse56 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse56')")
ADD_TEST(test_sparse63 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse63')")
ADD_TEST(test_sparse64 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse64')")
ADD_TEST(test_sparse65 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse65')")
ADD_TEST(test_sparse66 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse66')")
ADD_TEST(test_sparse67 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse67')")
ADD_TEST(test_sparse71 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse71')")
ADD_TEST(test_sparse72 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse72')")
ADD_TEST(test_sparse73 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse73')")
ADD_TEST(test_sparse81 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse81')")
ADD_TEST(test_sparse83 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse83')")
ADD_TEST(test_sparse116 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse116')")
ADD_TEST(test_ones1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_ones1')")
ADD_TEST(wbtest_num2str_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=num2str(x1)','wbtest_num2str_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_num2str1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_num2str1')")
ADD_TEST(test_sort ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sort')")
ADD_TEST(wbtest_sort_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=sort(x1)','wbtest_sort_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_sort_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=sort(x1,2)','wbtest_sort_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_sort_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=sort(x1,2,''descend'')','wbtest_sort_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_sort_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=sort(x1)','wbtest_sort_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_sort_5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=sort(x1,2)','wbtest_sort_5','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_sort_6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=sort(x1,2,''descend'')','wbtest_sort_6','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_unique_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=unique(x1)','wbtest_unique_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_unique_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3]=unique(x1)','wbtest_unique_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_unique_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=unique(x1,''rows'')','wbtest_unique_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_unique_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3]=unique(x1,''rows'')','wbtest_unique_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_nan_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=nan','wbtest_nan_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_sparse69 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse69')")
ADD_TEST(test_zeros1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_zeros1')")
ADD_TEST(test_cell1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_cell1')")
ADD_TEST(test_reshape1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_reshape1')")
ADD_TEST(test_resize1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize1')")
ADD_TEST(test_resize2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize2')")
ADD_TEST(test_resize3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize3')")
ADD_TEST(test_resize4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize4')")
ADD_TEST(test_resize5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize5')")
ADD_TEST(test_resize6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize6')")
ADD_TEST(test_resize7 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_resize7')")
ADD_TEST(test_reshape1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_reshape1')")
ADD_TEST(test_reshape2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_reshape2')")
ADD_TEST(wbtest_rcond_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$near#y1=rcond(x1)','wbtest_rcond_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=find(x1)','wbtest_find_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=find(x1,2)','wbtest_find_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=find(x1,2,''first'')','wbtest_find_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=find(x1,2,''last'')','wbtest_find_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=find(x1)','wbtest_find_5','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_6 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2]=find(x1,2)','wbtest_find_6','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_7 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3]=find(x1)','wbtest_find_7','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_find_8 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#[y1,y2,y3]=find(x1,2)','wbtest_find_8','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_sparse20 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse20')")
ADD_TEST(test_sparse21 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse21')")
ADD_TEST(test_sparse68 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse68')")
ADD_TEST(test_sparse70 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse70')")
ADD_TEST(wbtest_permute_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=permute(x1,[2,1])','wbtest_permute_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_permute_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=size(permute(x1,[3,4,2,1]))','wbtest_permute_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_permute1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_permute1')")
ADD_TEST(test_permute2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_permute2')")
ADD_TEST(wbtest_repmat_1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=repmat(x1,[1,1,3])','wbtest_repmat_1','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_repmat_2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=repmat(x1,[5,1])','wbtest_repmat_2','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_repmat_3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=repmat(x1,1,2)','wbtest_repmat_3','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(wbtest_repmat_4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wb_test('@$exact#y1=repmat(x1,2,1)','wbtest_repmat_4','${CMAKE_SOURCE_DIR}/tests/reference')")
ADD_TEST(test_repmat1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_repmat1')")
ADD_TEST(test_repmat2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_repmat2')")
ADD_TEST(test_repmat3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_repmat3')")
ADD_TEST(test_diag1 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_diag1')")
ADD_TEST(test_diag2 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_diag2')")
ADD_TEST(test_diag3 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_diag3')")
ADD_TEST(test_diag4 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_diag4')")
ADD_TEST(test_diag5 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_diag5')")
ADD_TEST(test_sparse74 ${FreeMat_Loc} "-e" "-nogui" "-t" "-nogreet" "-p" "${CMAKE_SOURCE_DIR}/tests/array" "-f" "wrap_test('test_sparse74')")
